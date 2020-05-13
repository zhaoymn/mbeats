# -*- coding:utf-8 -*-
import http.client
import time
import os,sys
import ntplib
import win32api


c = ntplib.NTPClient()
response = c.request('pool.ntp.org') 
ts_stamp = response.tx_time
ts = time.localtime(ts_stamp)
ttime = time.localtime(time.mktime(ts) - 1 * 60 * 60)  
time_cls = ttime
win32api.SetSystemTime(time_cls.tm_year, time_cls.tm_mon, time_cls.tm_wday, time_cls.tm_mday, time_cls.tm_hour, time_cls.tm_min, time_cls.tm_sec, 0)

print("time synchronized!")
