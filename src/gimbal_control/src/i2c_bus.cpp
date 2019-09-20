#include "gimbal_control/i2c_bus.h"
#include <linux/i2c-dev.h>  // I2C SLAVE
#include <fcntl.h>          // open() write()
#include <sys/ioctl.h>      // ioctl()
#include <errno.h>          // errno for Linux
#include "ros/ros.h"

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

    buf[0] = speed_command_pan;
    buf[1] = speed_command_tilt;

    if(write(_file, buf, 4) != 4) {
        ROS_ERROR("Failed to Write (%d): %s ", errno, strerror(errno));
    }
}
