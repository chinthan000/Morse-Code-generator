const int buzzerPin = 8;
const int dotDuration = 100; // Duration of a dot in milliseconds

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter text to convert to Morse code:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.toUpperCase(); // Convert input to uppercase
    for (int i = 0; i < input.length(); i++) {
      char c = input.charAt(i);
      if (c == ' ') {
        delay(dotDuration * 7); // Space between words
      } else {
        playMorseCode(c);
        delay(dotDuration * 3); // Space between letters
      }
    }
    Serial.println("Morse code generation complete.");
  }
}

void playMorseCode(char c) {
  String morseCode = getMorseCode(c);
  for (int i = 0; i < morseCode.length(); i++) {
    if (morseCode.charAt(i) == '.') {
      playDot();
    } else if (morseCode.charAt(i) == '-') {
      playDash();
    }
    delay(dotDuration); // Space between symbols
  }
}

void playDot() {
  digitalWrite(buzzerPin, HIGH);
  delay(dotDuration);
  digitalWrite(buzzerPin, LOW);
  delay(dotDuration); // Space between symbols
}

void playDash() {
  digitalWrite(buzzerPin, HIGH);
  delay(dotDuration * 3);
  digitalWrite(buzzerPin, LOW);
  delay(dotDuration); // Space between symbols
}

String getMorseCode(char c) {
  switch (c) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    default: return "";
  }
}
