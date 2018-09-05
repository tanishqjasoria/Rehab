import serial

ser = serial.Serial('/dev/ttyUSB0' , 115200)
text_file = open("test_data.txt",'w')
while True:
        x= ser.readline()
        print(x),
        #text_file.write(x)
        #text_file.flush()

