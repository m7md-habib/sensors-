const int irPin = 3;
const int buzzerPin = 4;


const int dotDuration = 200;

void dot() {
  tone(buzzerPin, 1000);
  delay(dotDuration);
  noTone(buzzerPin);
  delay(dotDuration);
}

void dash() {
  tone(buzzerPin, 1000);
  delay(dotDuration * 3);
  noTone(buzzerPin);
  delay(dotDuration);
}

void pauseBetweenLetters() {
  delay(dotDuration * 3);
}

void pauseBetweenWords() {
  delay(dotDuration * 7);
}

void sendMorseChar(char c) {
  switch (c) {
    case 'M':
      dash();
      dash();
      break;
    case '7':
      dash();
      dash();
      dot();
      dot();
      dot();
      break;
    case 'D':
      dash();
      dot();
      dot();
      break;
  }
}

void sendMorseMessage(const char* msg) {
  for (int i = 0; msg[i] != '\0'; i++) {
    sendMorseChar(msg[i]);
    pauseBetweenLetters();
  }
}

void setup() {
  pinMode(irPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int irState = digitalRead(irPin);

  if (irState == LOW) {
    Serial.println("Motion detected: sending Morse code");
    sendMorseMessage("M7MD");  
    pauseBetweenWords();
  } else {
    delay(100);
  }
}
