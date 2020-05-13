import time
import ntplib

c = ntplib.NTPClient()
for i in range(0,100):
    t1 = time.time()
    response = c.request('ntp.api.bz')
    ts = response.tx_time
    print(ts)
    t2 = time.time()
    print("elapse time: "+str(t2-t1))
