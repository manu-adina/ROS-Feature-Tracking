#include "gimbal_control/PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Begin(double Kp, double Ki, double Kd) {
    _Kp = Kp;
    _Ki = Ki;
    _Kd = Kd;

    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::Update(cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return -_Kp * p_error - _kd * d_error - _Ki * i_error;
}
