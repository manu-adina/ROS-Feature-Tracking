#include <string>
#include "vision_tracking/Position.h"

class I2CBus {
    public:
        I2CBus();
        int Begin(std::string port, uint16_t arduino_addr);
        int Send(const vision_tracking::Position::ConstPtr &msg);
        ~I2CBus();
    private:
        std::string _port;
        int _file;
        int _arduino_addr; 
};
