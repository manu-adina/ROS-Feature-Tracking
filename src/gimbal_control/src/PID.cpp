#include "gimbal_control/PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Begin(double Kp, double Ki, double Kd) {
    _Kp = Kp;
    _Ki = Ki;
    _Kd = Kd;

    _p_error = 0;
    _i_error = 0;
    _d_error = 0;
}

void PID::Update(int cte) {
    _d_error = cte - _p_error;
    _p_error = cte;
    _i_error += cte;
}

double PID::TotalError() {
    return -_Kp * _p_error - _Kd * _d_error - _Ki * _i_error;
}
