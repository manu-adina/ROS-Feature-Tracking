#include "gimbal_control/i2c_bus.h"
#include "vision_tracking/Position.h"
#include "ros/console.h"
#include "ros/ros.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "gimbal_control_node");
    ros::NodeHandle gimbal_control_nh;

    // Get params from the params file.
    std::string port = "/dev/i2c-1";
    uint16_t arduino_addr = 0x04;
    //gimbal_control_nh.getParam("i2c_port", port);
    //gimbal_control_nh.getParam("slave_arduino_address", arduino_addr);

    // Start an i2c bus
    I2CBus i2c_bus;
    if(i2c_bus.Begin(port, arduino_addr) != 0) {
        return -1;
    };

    ros::Subscriber gimbal_control_sub = gimbal_control_nh.subscribe("vision_position", 1, &I2CBus::Send, &i2c_bus);


    //ros::Subscriber gimbal_control_sub = gimbal_control_nh.subscribe("vision_position", 1, PID::Compare, &PID);

    //TODO: Params -- Not now.
    //TODO: Messages -- now
    //TODO: Package.xml

    ros::spin();

    return 0;

}
