import serial
import os
import sys
import ntplib
import time


c = ntplib.NTPClient()
ser = serial.Serial("COM22",9600,timeout=30)
#serial.open()
for angle in range(75,106):
    ser.write(str)
    #s.send_cmd(str)
