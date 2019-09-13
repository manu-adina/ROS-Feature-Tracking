#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char argv**) {
    ros::init(argc, argv);
    ros::NodeHandle gimbal_control_node;

    I2C i2c_channel;

    ros::Subscriber gimbal_control_sub = gimbal_control_node.subscribe("feature_position", 1, &I2C::SendCommand, &i2c_channel);



    ros::spin();
    return 0;

}
