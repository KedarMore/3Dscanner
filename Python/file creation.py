#<SYNTAX>
#file=open("/home/kedar/OpenSource/3Dscanner/File/h.txt",'w')
#file.write("\nx=%d" %x)
#file.close()
#</SYNTAX>

a=[1,4,5,64,4]

file=open("/home/kedar/OpenSource/3Dscanner/File/h.txt",'a')
for x in range(5):
    file.write("x=%d\n" %a[x])
    pass
file.close()
