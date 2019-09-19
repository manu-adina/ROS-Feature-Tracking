#include "/gimbal_control/gimbal_control.h"

#define COMMAND_OFFSET 1023
#define MAX_COMMAND 2037
#define MIN_COMMAND 0


GimbalControl::GimbalControl(uint16_t arduino_address, int capture_resolution_x, std::string port) {
    /**
     * arduino
     * resolution x
     * resolution y
     * i2c port
     * pid vars x
     * pid vars y
    **/

    _arduino_address = arduino_address;
    _centre_point_x = capture_resolution_x / 2;
    _centre_point_y = capture_resolution_y / 2;

    _i2c_bus.Begin(_port, _arduino_address);
    _pid_x.Begin(); // TODO
    _pid_y.Begin(); // TODO

    ros::NodeHandle gimbal_control_nh;
    ros::Subscriber gimbal_control_sub = gimbal_control_nh.subscribe("vision_position", 1, &I2CBus::Send, &i2c_bus); //TODO
    ros::spin(); //TODO Should work.
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
