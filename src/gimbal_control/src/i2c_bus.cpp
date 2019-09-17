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
        ROS_ERROR("Failed to Open I2C Bus %s", strerror(errno));
        return -1;
    }
    
    if(ioctl(_file, I2C_SLAVE, _arduino_addr) < 0) {
        ROS_ERROR("Failed to Open Arduino Port %s", strerror(errno));
        return -1;
    }

    ROS_INFO("Successfully Opened I2C Communication");

    return 0;
}

void I2CBus::Send(const vision_tracking::Position::ConstPtr &msg) {

    ROS_DEBUG("Received X: %d, and Y: %d.", msg->position_x, msg->position_y);

    uint16_t buf[2] = {0};

    buf[0] = msg->position_x;
    buf[1] = msg->position_y;

    if(write(_file, buf, 4) != 4) {
        ROS_ERROR("Failed to Write (%d): %s ", errno, strerror(errno));
    }
}

