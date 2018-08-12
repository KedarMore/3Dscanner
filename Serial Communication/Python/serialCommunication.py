import serial
arduinoSerial=serial.Serial('COM12',9600)
arduinoSerial.readline()

for x in range(100):
    array[x]=arduinoSerial.readline()
    pass