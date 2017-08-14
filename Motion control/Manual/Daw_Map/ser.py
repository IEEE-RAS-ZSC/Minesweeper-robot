import serial

mine = open("new.txt","w")
def wr(y) :
    
    mine.write(y)
    


def seerial():
    
    ser = serial.Serial('/dev/ttyACM0',9600)
    i = 0

    while i<10:
        x = str(ser.readline())
        print (x)
        wr(x)
        i = i + 1
    mine.close()
        
        
        
seerial()


