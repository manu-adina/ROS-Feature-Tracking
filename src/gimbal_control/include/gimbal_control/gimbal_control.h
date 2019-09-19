#include "PID.h"
#include "i2c_bus.h"

class GimbalControl {
    public:
        GimbalControl();
        ~GimbalControl();
        void compareCallback();

    private:
        PID _pid_x;
        PID _pid_y;

        I2CBus _i2c_bus;
        int _centre_point_x;
        int _centre_point_y;
};
