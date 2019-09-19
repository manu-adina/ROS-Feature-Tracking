#include "gimbal_control/i2c_bus.h"
#include "gimbal_control/gimbal_control.h"
#include "vision_tracking/Position.h"
#include "ros/console.h"
#include "ros/ros.h"


int main(int argc, char **argv) {

    ros::init(argc, argv, "gimbal_control_node");
//    ros::NodeHandle gimbal_control_nh;

    // Get params from the params file.
//    std::string port = "/dev/i2c-1";
//    uint16_t arduino_addr = 0x04;
//    int capture_resolution_x = 480;
//    int capture_resolution_y = 320;

    //gimbal_control_nh.getParam("i2c_port", port);
    //gimbal_control_nh.getParam("slave_arduino_address", arduino_addr);
    //gimbal_control_nh.getParam("capture_resolution", capture_resolution);

    // Start an i2c bus
//    I2CBus i2c_bus;
//    if(i2c_bus.Begin(port, arduino_addr) != 0) {
//        return -1;
//    };

    //ros::Subscriber gimbal_control_sub = gimbal_control_nh.subscribe("vision_position", 1, PID::Compare, &PID);

    GimbalControl gimbal_control_node;
    ros::spin();

    return 0;

}
