#include <cmath>
#include "hybrid_controller.h"

double HybridController::compute_u(double current_T, const std::vector<double>& future_T_amb) {
    double error = T_setpoint - current_T;
    if (std::abs(error) > error_threshold) {
        return mpc_controller.compute_u(current_T, future_T_amb);
    } else {
        return pid_controller.compute_u(current_T);
    }
}