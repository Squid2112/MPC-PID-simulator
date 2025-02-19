#ifndef MPC_CONTROLLER_H
#define MPC_CONTROLLER_H

#include "constants.h"
#include <vector>

class MPCController {
public:
    MPCController() = default;
    double compute_u(double current_T, const std::vector<double>& future_T_amb);

private:
    double compute_sum_s(int i);
    double compute_alpha_i(int i);
    double compute_beta_i(int i);
    double compute_gamma_i(int i, const std::vector<double>& future_T_amb, int current_step);
};

#endif // MPC_CONTROLLER_H