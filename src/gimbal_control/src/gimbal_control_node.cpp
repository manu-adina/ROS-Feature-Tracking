#include "gimbal_control/gimbal_control.h"
#include "ros/ros.h"


int main(int argc, char **argv) {

    ros::init(argc, argv, "gimbal_control_node");
    GimbalControl gimbal_control_node;
    gimbal_control_node.Run();
    ros::spin();

    return 0;

}
