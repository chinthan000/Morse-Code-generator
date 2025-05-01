"# Morse-Code-generator" 



🎙️ Voice to Morse Code Generator 🔔
Convert spoken words into Morse code using Python & Arduino!
📌 Overview
This project bridges voice recognition and hardware control to create an interactive system that listens to your speech and translates it into Morse code signals through a buzzer connected to an Arduino. It's a fun and educational blend of software and electronics.

🚀 How It Works
Voice Input (Python):

Captures audio via a microphone.

Converts speech to text using speech_recognition and Google Speech API.

Sends the text to the Arduino over a serial connection.

Morse Output (Arduino):

Receives text over Serial.

Translates each character to Morse code.

Activates a buzzer to play corresponding dots (•) and dashes (—).

🧰 Tech Stack
Hardware:
Arduino UNO

Buzzer

Jumper wires

USB cable for Serial connection

Software:
Python (with speech_recognition and pyserial)

Arduino IDE

📂 File Structure
voice_to_morse.py – Listens to voice and sends text to Arduino.

morse_buzzer.ino – Receives and plays Morse code using a buzzer.

🛠️ Setup Instructions
1. Arduino
Connect the buzzer to pin 8 and GND.

Upload the morse_buzzer.ino sketch using Arduino IDE.

2. Python Environment
bash
Copy
Edit
pip install pyserial speechrecognition
3. Run Python Script
Plug in your Arduino and find the correct COM port.

Update COM3 in the Python script if needed.

Run the Python file:
bash
Copy
Edit
python voice_to_morse.py


Add support for multiple languages.

🙌 Credits
Made with ❤️ using Python + Arduino by [CHINTHAN000]
Feel free to fork or contribute!
