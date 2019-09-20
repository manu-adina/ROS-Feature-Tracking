#ifndef PID_H
#define PID_H

class PID {
    public:
        PID();
        ~PID();
        void Begin(double Kp, double Ki, double Kd);
        void Update(double cte);
        double TotalError();

    private:
        double _Kp;
        double _Ki;
        double _Kd;
        double _p_error;
        double _i_error;
        double _d_error;
};

#endif
