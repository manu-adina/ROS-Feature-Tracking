#include "i2c_bus.cpp"

class I2CBus {
    public:
        I2C();
        int Begin();
        int Send(uint16_t channel_0, uint16_t channel_1, uint16_t channel_2);
        ~I2C();
    private:
        std::string _port;
        int _file;
        int arduino_addr; 
};
