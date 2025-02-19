#ifndef HYBRID_CONTROLLER_H
#define HYBRID_CONTROLLER_H

#include "pid_controller.h"
#include "mpc_controller.h"

class HybridController {
public:
    HybridController(PIDController& pid, MPCController& mpc) : pid_controller(pid), mpc_controller(mpc) {}
    double compute_u(double current_T, const std::vector<double>& future_T_amb);

private:
    PIDController& pid_controller;
    MPCController& mpc_controller;
};

#endif // HYBRID_CONTROLLER_H