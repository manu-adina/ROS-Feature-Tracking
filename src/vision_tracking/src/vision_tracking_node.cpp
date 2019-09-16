#include <ros/ros.h>

int main(int argc, char argv**) {
    ros::init(argc, argv);
    ros::NodeHandle vision_tracking_nh;

    ros::Publisher postion_pub = vision_tracking_nh.advertise<std_msgs::String>("vision_position", 10);

    ros::Rate loop_rate(10);
    int count = 0;
    while(ros::ok()) {
        std_msgs::String msg;

        position_pub.publish(msg); 
        ros::spinOnce();
    }

    ros::spin();
}
