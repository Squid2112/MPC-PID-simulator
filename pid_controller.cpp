#include "pid_controller.h"

void PIDController::set_initial_error(double error) {
    previous_error = error;
}

double PIDController::compute_u(double current_T) {
    double error = T_setpoint - current_T;
    sum_e_dt += error * dt;
    double proportional_term = Kp * error;
    double integral_term = Ki * sum_e_dt;
    double derivative_term = Kd * (error - previous_error) / dt;
    double u = proportional_term + integral_term + derivative_term;
    previous_error = error;
    return u;
}