#!/usr/bin/python3.9

import serial
import time
import string

# reading and writing data from and to arduino serially.
# rfcomm0 -> this could be different
ser = serial.Serial("/dev/rfcomm", 9600)

# print(bytes("0", 'utf-8'))
#ser.write(bytes("1", 'utf-8'))
ser.write(bytes("0000", 'utf-8'))
while True:
	if ser.in_waiting > 0:
		rawserial = ser.readline()
		cookedserial = rawserial.decode('utf-8').strip('\r\n')
		print(cookedserial)
