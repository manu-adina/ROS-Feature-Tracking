#include "gimbal_control/gimbal_control.h"
#include "vision_tracking/Position.h"
#include "ros/ros.h"

#define COMMAND_OFFSET 1023
#define MAX_COMMAND 2037
#define MIN_COMMAND 0


GimbalControl::GimbalControl() {
    /**
     * arduino
     * resolution x
     * resolution y
     * i2c port
     * pid vars x
     * pid vars y
    **/

    _centre_point_x = 320;
    _centre_point_y = 240;
    uint16_t arduino_address = 0x04;
    std::string port = "/dev/i2c-1";

    double Kp_x, Kp_y = 5.0;
    double Ki_x, Ki_y = 1.0;
    double Kd_x, Kd_y = 1.0;

    _i2c_bus.Begin(port, arduino_address);
    _pid_x.Begin(Kp_x,Ki_x,Kd_x);
    _pid_y.Begin(Kp_y,Ki_y,Kd_y);

    ros::NodeHandle gimbal_control_nh;
    ros::Subscriber gimbal_control_sub = gimbal_control_nh.subscribe("vision_position", 1, &GimbalControl::compareCallback, this); //TODO
    ros::spin();
}

void GimbalControl::compareCallBack(const vision_tracking::Position::ConstPtr &msg) {
    // Get vision_position from the message.
    position_x = msg->position_x;
    position_y = msg->position_y;

    // Get the error for the PID
    int cte_x = _centre_point_x - position_x;
    int cte_x = _centre_point_y - position_y;

    _pid_x.Update(cte_x);
    _pid_y.Update(cte_y);

    // Converting to 0 - 2047 space.
    speed_command_pan  = _pid_x.TotalError() + COMMAND_OFFSET;
    speed_command_tilt = _pid_y.TotalError() + COMMAND_OFFSET;

    // Making sure the commands are within 0 - 2047 domain.
    speed_command_pan  = speed_command_pan  > MAX_COMMAND ? MAX_COMMAND : speed_command_pan;
    speed_command_pan  = speed_command_pan  < MIN_COMMAND ? MIN_COMMAND : speed_command_yaw;

    speed_command_tilt = speed_command_tilt > MAX_COMMAND ? MAX_COMMAND : speed_command_pan;
    speed_command_tilt = speed_command_rilt < MIN_COMMAND ? MIN_COMMAND : speed_command_yaw;
     
    _i2c_bus.Send(speed_command_pan, speed_command_tilt);
}
