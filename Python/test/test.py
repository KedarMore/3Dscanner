import serial
arduinoSerial=serial.Serial('/dev/ttyACM0',9600)
arduinoSerial.readline()

file=open("/home/kedar/OpenSource/3Dscanner/File/h.txt",'w')

while True:
    #print arduinoSerial.readline()
    x=arduinoSerial.readline()
    number=float(x)
    if number>=1:
        print number
        #print number
        file.write("\nx=%.3f" %number)
        pass
    pass
file.close()
