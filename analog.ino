const int ldrPin = A0;       // مدخل LDR
const int ledPin = 13;       // LED مدمج في الأردوينو (للتجربة)
int threshold = 600;         // العتبة: تحتها يعتبر ظلام

void setup() {
  pinMode(ledPin, OUTPUT);   
  Serial.begin(9600);        // تشغيل الشاشة التسلسلية
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // قراءة قيمة الضوء
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);           // طباعة القيمة

  // شرط: إذا الإضاءة أقل من العتبة → شغل الـ LED
  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);       // تشغيل
  } else {
    digitalWrite(ledPin, LOW);        // إطفاء
  }

  delay(500);  // تأخير بسيط
}
