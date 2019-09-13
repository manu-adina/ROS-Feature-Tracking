#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <ros/console.h>
#include <cstring.h> // For c_str()

I2CBus::I2CBus() {};

int I2C::Begin(std::string::port, int arduino_addr) {
    _port = port;
    _arduino_addr = arduino_addr;

    if((_file = open(port.c_str(), O_RDWR)) < 0) 
        ROS_ERROR("Failed to Open I2C Bus " << strerror(errno));
        return -1;
    }
    
    if(ioctl(_file, I2C_SlAVE, _arduino_addr) < 0) {
        ROS_ERROR("Failed to Open Arduino Port " << strerror(errno));
        return -1;
    }
}

I2C::Send(uint16_t pan, uint16_t tilt, uint16_t roll) {
    uint16_t buf[3] = {0};

    buf[0] = pan;
    buf[1] = tilt;
    buf[2] = roll;

    if(write(file, buf, 6) != 6) {
        ROS_ERROR("Failed to Write " << strerror(errno));
        return -1;
    }
} 

