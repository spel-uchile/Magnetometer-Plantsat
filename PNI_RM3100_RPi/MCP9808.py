#!/usr/bin/env python
from smbus import SMBus
import time

class MCP9808:
    def __init__(self, i2c_address, bus = 1):
        self.i2cbus = SMBus(bus)
        self.i2c_address = i2c_address
        
    def read16(self, reg):
        value = self.i2cbus.read_word_data(self.i2c_address, reg & ~0x80)
        print(value)
        bval = value.to_bytes(2,'big')
        print(bval)
        return int.from_bytes(bval, 'little')
    
    def read_temp(self):
        value = self.i2cbus.read_word_data(self.i2c_address, 0x05)
        bval = value.to_bytes(2,'big')
        ivalue = int.from_bytes(bval, 'little')
        #print(bin(ivalue))
        temp = (0x1FFF & ivalue)
        #print(bin(temp))
        l_temp = (0x00FF & temp)
        #print(bin(l_temp))
        h_temp = (0xFF00 & temp)
        #print(bin(h_temp))
        sign = (0x1000 & temp)
        #print(bin(sign))
        #print(bin(l_temp>>4))
        #print(bin(h_temp>>4))
        
        if sign == 0:
            return (float(h_temp>>4) + float(l_temp)*2**-4)
        else:
            return 256 -(float(h_temp>>4) + float(l_temp)*2**-4)
    
    def check_masurement(self):
        value = self.read16(0x06)
        value2 = self.read16(0x07)

        if (value == 84) and (value2 == 1024):
            return True
        else:
            return False


    
def main():
    temp1 = MCP9808(0x18)
    temp2 = MCP9808(0x19)
    
    counter1 = 0
    
    tstart = time.time()
    tfinish = tstart +4* 3600
    
    while(time.time() <= tfinish):
    #while True:
        
        start = time.time()
        finish = start + 1
        counter1 += 1
        
        while (time.time()<= finish):
            tmp1 = temp1.read_temp()
            tmp2 = temp2.read_temp()
            time.sleep(1)
            
        print(counter1, tmp1, tmp2)
            
if __name__ == "__main__":
    main()
    #temp1 = MCP9808(0x18)
    #for i in range(120):
        #print(temp1.read16(0x05))
    #    print(temp1.read_temp())
    #    time.sleep(1)
    #print(temp1.check_masurement())
    