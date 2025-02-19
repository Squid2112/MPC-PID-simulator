#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include "constants.h"

class PIDController {
public:
    PIDController() : sum_e_dt(0.0), previous_error(0.0) {}
    void set_initial_error(double error);
    double compute_u(double current_T);

private:
    double sum_e_dt;
    double previous_error;
};

#endif // PID_CONTROLLER_H