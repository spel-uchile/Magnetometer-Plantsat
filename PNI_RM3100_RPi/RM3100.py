#!/usr/bin/env python
from smbus import SMBus
import time

class RM3100:
    def __init__(self, i2c_address, bus = 1):
        self.i2cbus = SMBus(bus)
        self.i2c_address = i2c_address
        
    def read8(self, reg):
        return self.i2cbus.read_byte_data(self.i2c_address, reg & ~0x80)

    def read16(self, reg):
        value = self.i2cbus.read_word_data(self.i2c_address, reg & ~0x80)
        bval = value.to_bytes(2,'big')
        return int.from_bytes(bval, 'little')

    def write8(self, reg, value):
        self.i2cbus.write_byte_data(self.i2c_address, reg, value)
        return True
    
    def write16(self, reg, value):
        bval = value.to_bytes(2,'big')
        self.i2cbus.write_word_data(self.i2c_address, reg, int.from_bytes(bval, 'little'))
        return True
    
    def check_masurement(self):
        value = self.read8(0xB4)

        if len(bin(value)) == 10:
            return True
        else:
            return False

    def read_measurements(self):
        measurements = []
        measurements.append(self.i2cbus.read_byte_data(self.i2c_address, 0xA4 & ~0x80))
        
        for i in range(8):
            measurements.append(self.i2cbus.read_byte(self.i2c_address))
        
        
        if measurements[0]>=64:
            x = int.from_bytes([255,measurements[0],measurements[1],measurements[2]],'big',signed=True)
        else:
            x = int.from_bytes([0,measurements[0],measurements[1],measurements[2]],'big',signed=True)
            
        if measurements[3] >=64:
            y = int.from_bytes([255,measurements[3],measurements[4],measurements[5]],'big',signed=True)
        else:
            y = int.from_bytes([0,measurements[3],measurements[4],measurements[5]],'big',signed=True)
            
        if measurements[6] >=64:
            z = int.from_bytes([255,measurements[6],measurements[7],measurements[8]],'big',signed=True)
        else:
            z = int.from_bytes([0,measurements[6],measurements[7],measurements[8]],'big',signed=True)
        
        measurements_d = {'x': x , 'y':y, 'z':z}
        return measurements_d
        
    
def main():
    mag = RM3100(0x21)
    #i2cbus = SMBus(1) #Create I2C bus
    #i2c_address = 0x20

    # Count Cycles Write Registers
    RM3100_REGISTER_CMM = 0x01
    RM3100_REGISTER_CMX = 0x04
    RM3100_REGISTER_CLX = 0x05
    RM3100_REGISTER_CMY = 0x06
    RM3100_REGISTER_CLY = 0x07
    RM3100_REGISTER_CMZ = 0x08
    RM3100_REGISTER_CLZ = 0x09
    RM3100_REGISTER_TMRC = 0x0B


    # Count Cycles Read Registers
    RM3100_REGISTER_RCMX = 0x84
    RM3100_REGISTER_RCLX = 0x85
    RM3100_REGISTER_RCMY = 0x86
    RM3100_REGISTER_RCLY = 0x87
    RM3100_REGISTER_RCMZ = 0x88
    RM3100_REGISTER_RCLZ = 0x89
    RM3100_REGISTER_RTMRC = 0x8B

    # Test Registers
    RM3100_REGISTER_TEST = 0xB6

    # STATUS Register
    RM3100_REGISTER_STATUS = 0xB4
    
    #reg = read8(i2cbus, i2c_address, RM3100_REGISTER_TEST&~0x80)
    reg = mag.read8(RM3100_REGISTER_TEST)
    #print(reg)
    eh = mag.write8(RM3100_REGISTER_CMM, 0x79)
    #print(eh)
    ccx = mag.write16(RM3100_REGISTER_CMX, 800)
    ccy = mag.write16(RM3100_REGISTER_CMY, 800)    
    ccz = mag.write16(RM3100_REGISTER_CMZ, 800)
    #print(ccx)
    #print(ccy)
    #print(ccz)
    rccx = mag.read16(RM3100_REGISTER_CMX)
    rccy = mag.read16(RM3100_REGISTER_CMY)    
    rccz = mag.read16(RM3100_REGISTER_CMZ)
    #print(rccx)
    #print(rccy)
    #print(rccz)
    #print(mag.read8(RM3100_REGISTER_CMX))
    #print(mag.read8(RM3100_REGISTER_CMX+1))
    counter1 = 0
    
    tstart = time.time()
    tfinish = tstart +4* 3600
    
    while(time.time() <= tfinish):
    #while True:
        
        start = time.time()
        finish = start + 1
        x = 0
        y = 0
        z = 0
        counter2 = 0
        counter1 += 1
        
        while (time.time()<= finish):
            if mag.check_masurement():
                mag_data = mag.read_measurements()
                x += mag_data['x']
                y += mag_data['y']
                z += mag_data['z']
                counter2 += 1
                #print(mag_data['x'], mag_data['y'], mag_data['z'])
                #print(counter1, counter2, x, y, z)
                #time.sleep(0.027)
                while (mag.check_masurement()==True):
                    pass
            #else:
                #break
    
        print(counter1, counter2, x, y, z)
if __name__ == "__main__":
    main()
