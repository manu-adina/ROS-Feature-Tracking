#include "gimbal_control/pid.h"
#include "gimbal_control/i2c_bus.h"
#include "vision_tracking/Position.h"
#include "ros/ros.h"

class GimbalControl {
    public:
        GimbalControl();
        void Run();
        void compareCallback(const vision_tracking::Position::ConstPtr &msg);

    private:
        PID _pid_x;
        PID _pid_y;

        I2CBus _i2c_bus;
        int _centre_point_x;
        int _centre_point_y;

        ros::NodeHandle _gimbal_control_nh;
};
