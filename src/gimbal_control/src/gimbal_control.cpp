#include "gimbal_control/gimbal_control.h"

#define COMMAND_OFFSET 1023.0
#define MAX_COMMAND 2037
#define MIN_COMMAND 0

GimbalControl::GimbalControl() {

    // Get params for this node.
    int resolution_x, resolution_y;
    _gimbal_control_nh.param<int>("/vision_tracking_node/resolution_x", resolution_x, 320);
    _gimbal_control_nh.param<int>("/vision_tracking_node/resolution_y", resolution_y, 240);
    _centre_point_x = resolution_x / 2;
    _centre_point_y = resolution_y / 2;

    int arduino_address;
    _gimbal_control_nh.param<int>("/gimbal_control_node/arduino_address", arduino_address, 4);

    std::string port;
    _gimbal_control_nh.param<std::string>("/gimbal_control_node/i2c_port", port, "/dev/i2c-1");

    double Kp_x ,Ki_x, Kd_x;
    _gimbal_control_nh.param<double>("/gimbal_control_node/Kp_x", Kp_x, 5.0);
    _gimbal_control_nh.param<double>("/gimbal_control_node/Ki_x", Ki_x, 0.001);
    _gimbal_control_nh.param<double>("/gimbal_control_node/Kd_x", Kd_x, 0.0001);
    
    double Kp_y, Ki_y, Kd_y; 
    _gimbal_control_nh.param<double>("/gimbal_control_node/Kp_y", Kp_y, 5.0);
    _gimbal_control_nh.param<double>("/gimbal_control_node/Ki_y", Ki_y, 0.001);
    _gimbal_control_nh.param<double>("/gimbal_control_node/Kd_y", Kd_y, 0.001);

    // Start PIDs and I2C port.
    _i2c_bus.Begin(port, arduino_address);
    _pid_x.Begin(Kp_x,Ki_x,Kd_x);
    _pid_y.Begin(Kp_y,Ki_y,Kd_y);
}

void GimbalControl::Run() {
    ros::Subscriber gimbal_control_sub = _gimbal_control_nh.subscribe("vision_position", 1, &GimbalControl::compareCallback, this);
    ros::spin();
}

void GimbalControl::compareCallback(const vision_tracking::Position::ConstPtr &msg) {

    //If a feature wasn't detected, don't do anything.
    if(!msg->detected) return;

      // Get vision_position from the message.
    int position_x = msg->position_x;
    int position_y = msg->position_y;

    ROS_INFO("Position X: %d \t Position Y: %d", position_x, position_y);

      // Get the error for the PID
    double cte_x = static_cast<double>(_centre_point_x) - static_cast<double>(position_x);
    double cte_y = static_cast<double>(_centre_point_y) - static_cast<double>(position_y);

    ROS_INFO("CTE X: %f \t CTE Y: %f", cte_x, cte_y);

    _pid_x.Update(cte_x);
    _pid_y.Update(cte_y);

    ROS_INFO("PID Value X: %f \t PID Value Y: %f", _pid_x.TotalError(), _pid_y.TotalError());

    // Converting to 0 - 2047 space.
    double speed_command_pan  = _pid_x.TotalError() + COMMAND_OFFSET;
    double speed_command_tilt = _pid_y.TotalError() + COMMAND_OFFSET;

    // Making sure the commands are within 0 - 2047 domain.
    speed_command_pan  = speed_command_pan  > MAX_COMMAND ? MAX_COMMAND : speed_command_pan;
    speed_command_pan  = speed_command_pan  < MIN_COMMAND ? MIN_COMMAND : speed_command_pan;

    speed_command_tilt = speed_command_tilt > MAX_COMMAND ? MAX_COMMAND : speed_command_tilt;
    speed_command_tilt = speed_command_tilt < MIN_COMMAND ? MIN_COMMAND : speed_command_tilt;

    ROS_INFO("Pan Value: %f \t Tilt Value: %f", speed_command_pan, speed_command_tilt);
     
    _i2c_bus.Send(static_cast<int>(speed_command_pan), static_cast<int>(speed_command_tilt));
}

