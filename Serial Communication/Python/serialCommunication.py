import serial
arduinoSerial=serial.Serial('/dev/ttyACM0',9600)
arduinoSerial.readline()

while True:
    print arduinoSerial.readline()
    pass
