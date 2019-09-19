#include <string>
#include "vision_tracking/Position.h"

class I2CBus {
    public:
        I2CBus();
        int Begin(std::string port, uint16_t arduino_addr);
        void Send(uint16_t speed_command_x, uint16_t speed_command_y);
    private:
        std::string _port;
        int _file;
        int _arduino_addr; 
};
