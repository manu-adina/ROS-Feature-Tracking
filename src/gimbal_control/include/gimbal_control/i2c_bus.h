#include <string>
#include "vision_tracking/Position.h"

class I2CBus {
    public:
        I2CBus();
        int Begin(std::string port, uint16_t arduino_addr);
        void Send(const vision_tracking::Position::ConstPtr &msg);
    private:
        std::string _port;
        int _file;
        int _arduino_addr; 
};
