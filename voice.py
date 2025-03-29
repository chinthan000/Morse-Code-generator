import serial
import speech_recognition as sr
import time

# Initialize serial communication with Arduino
arduino = serial.Serial('COM3', 9600)  # Adjust 'COM3' if your port is different
time.sleep(2)  # Allow time for Arduino to initialize

# Initialize speech recognizer
recognizer = sr.Recognizer()



def listen_and_send():
    while True:
        try:
            with sr.Microphone() as source:
                print("Listening...")
                audio = recognizer.listen(source)
                
                print("Recognizing...")
                text = recognizer.recognize_google(audio)
                print("You said:", text)
                
                # Send recognized text to Arduino
                arduino.write((text + '\n').encode())
                
        except sr.UnknownValueError:
            print("Could not understand audio")
        except sr.RequestError as e:
            print(f"Could not request results; {e}")


   
if __name__ == "__main__":
    try:
        listen_and_send()
    except KeyboardInterrupt:
        print("Program stopped")
        arduino.close()
