#include "gimbal_control/i2c_bus.h"
#include <iostream>
#include "ros/ros.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string>
#include <errno.h>
//#include <cstring.h> // For c_str()

I2CBus::I2CBus() {};

int I2CBus::Begin(std::string::port, uint16_t arduino_addr) {
    _port = port;
    _arduino_addr = arduino_addr;

    if((_file = open(port.c_str(), O_RDWR)) < 0) {
        ROS_ERROR("Failed to Open I2C Bus " << strerror(errno));
        return -1;
    }
    
    if(ioctl(_file, I2C_SlAVE, _arduino_addr) < 0) {
        ROS_ERROR("Failed to Open Arduino Port " << strerror(errno));
        return -1;
    }
}

int I2CBus::Send(const vision_tracking::Position::ConstPtr &msg) {
    uint16_t buf[2] = {0};

    buf[0] = msg->position_x;
    buf[1] = msg->position_y;

    if(write(_file, buf, 4) != 4) {
        ROS_ERROR("Failed to Write " << strerror(errno));
        return -1;
    }
} 

