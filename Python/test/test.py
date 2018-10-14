import serial
arduinoSerial=serial.Serial('/dev/ttyACM0',9600)
arduinoSerial.readline()

file=open("/home/kedar/OpenSource/3Dscanner/File/h.txt",'w')

while True:
    print arduinoSerial.readline()
    x=arduinoSerial.readline()
    file.write("\nx=%c" %x)
    pass

file.close()
