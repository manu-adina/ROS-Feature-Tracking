#include "gimbal_control/i2c_bus.h"
#include <iostream>
#include "ros/ros.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> //open() write()
#include <linux/i2c-dev.h> //I2C_SLAVE
#include <sys/ioctl.h> //ioctl()
#include <string>
#include <errno.h> //errno for linux

I2CBus::I2CBus() {};

int I2CBus::Begin(std::string port, uint16_t arduino_addr) {
    _port = port;
    _arduino_addr = arduino_addr;

    if((_file = open(port.c_str(), O_RDWR)) < 0) {
        ROS_ERROR("Failed to Open I2C Bus (%d): %s", errno, strerror(errno));
        return -1;
    }
    
    if(ioctl(_file, I2C_SLAVE, _arduino_addr) < 0) {
        ROS_ERROR("Failed to Open Arduino Port (%d): %s", errno, strerror(errno));
        return -1;
    }

    ROS_INFO("Successfully Opened I2C Communication");

    return 0;
}

void I2CBus::Send(uint16_t speed_command_pan, uint16_t speed_command_tilt) {

    uint16_t buf[2] = {0};

    if(write(_file, buf, 4) != 4) {
        ROS_ERROR("Failed to Write (%d): %s ", errno, strerror(errno));
    }
}
