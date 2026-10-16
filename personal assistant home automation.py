import pyttsx3
import speech_recognition as sr
import serial

engine = pyttsx3.init()

port = 'COM3'
baud = 9600

try:
    ser = serial.Serial(port, baud)
except serial.SerialException:
    print(f"Could not open serial port {port}")
    ser = None

def speak(audio):
    rate = engine.getProperty('rate')
    engine.setProperty('rate', 180)
    engine.say(audio)
    engine.runAndWait()

def takeCommand():
    r = sr.Recognizer()

    try:
        with sr.Microphone() as source:
            print('Listening...')
            r.pause_threshold = 1
            audio = r.listen(source)

            print('Recognizing...')
            command = r.recognize_google(audio, language='en-in')
            print(f"User said: {command}")

    except Exception as ex:
        print(f"Error recognizing speech: {ex}")
        return 'none'
    return command.lower()

def greeting():
    speak("Hey bro! I am your personal assistant. How may I help you?")

if __name__ == '__main__':
    greeting()
    if ser is None:
        print("Serial port not available. Exiting.")
        exit(1)

    while True:
        command = takeCommand()

        if command == 'none':
            continue

        if 'on first light' in command:
            speak('Turning on the light 1')
            ser.write(b'U')

        elif 'off first light' in command:
            speak('Turning off the light 1')
            ser.write(b'u')

        elif 'on second light' in command:
            speak('Turning on the light 2')
            ser.write(b'S')

        elif 'off second light' in command:
            speak('Turning off the light 2')
            ser.write(b's')

        elif 'on third light' in command:
            speak('Turning on the light 3')
            ser.write(b'M')

        elif 'off third light' in command:
            speak('Turning off the light 3')
            ser.write(b'm')

        elif 'on lights' in command:
            speak('Turning on all lights')
            ser.write(b'A')

        elif 'off lights' in command:
            speak('Turning off all lights')
            ser.write(b'a')

        elif 'offline' in command:
            speak("Going offline. Goodbye!")
            break
