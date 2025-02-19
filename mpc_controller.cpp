#include "mpc_controller.h"
#include <cmath>

double MPCController::compute_sum_s(int i) {
    if (i == 0) return 0.0;
    double a = 1.0 - k * dt; // 0.4
    double sum = 0.0;
    for (int j = 0; j < i; ++j) {
        sum += pow(a, j);
    }
    return sum;
}

double MPCController::compute_alpha_i(int i) {
    double a = 1.0 - k * dt; // 0.4
    return pow(a, i);
}

double MPCController::compute_beta_i(int i) {
    double a = 1.0 - k * dt; // 0.4
    double b = dt; // 60
    double sum = 0.0;
    for (int j = 0; j < i; ++j) {
        sum += pow(a, j);
    }
    return b * sum;
}

double MPCController::compute_gamma_i(int i, const std::vector<double>& future_T_amb, int current_step) {
    double a = 1.0 - k * dt; // 0.4
    double c = k * dt; // 0.6
    double sum = 0.0;
    for (int j = 0; j < i; ++j) {
        int time_index = current_step + j;
        if (time_index < future_T_amb.size()) {
            sum += pow(a, i-1-j) * c * future_T_amb[time_index];
        }
    }
    return sum;
}

double MPCController::compute_u(double current_T, const std::vector<double>& future_T_amb) {
    double a = 1.0 - k * dt; // 0.4
    double b = dt; // 60
    double c = k * dt; // 0.6

    double numerator = 0.0;
    double denominator = 0.0;

    // Compute sums for each i from 1 to N
    for (int i = 1; i <= N; ++i) {
        double alpha_i = compute_alpha_i(i);
        double beta_i = compute_beta_i(i);
        double gamma_i = compute_gamma_i(i, future_T_amb, 0); // Assuming current_step=0 for simplicity, adjust as needed

        // Contribution from current T
        numerator += alpha_i * current_T * beta_i;
        // Contribution from T_amb terms
        numerator += gamma_i * beta_i;
        // Contribution from setpoint
        numerator -= T_setpoint * beta_i;

        denominator += beta_i * beta_i;
    }

    denominator = b * b * denominator + lambda * N;

    return -numerator / denominator;
}