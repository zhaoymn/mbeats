import serial
import os
import sys
import time


ser = serial.Serial("COM22",9600,timeout=30)
#serial.open()
while True:
    cmd = input("Enter your input: ")
    ser.write(cmd.encode())
