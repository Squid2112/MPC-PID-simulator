#include "HybridController.h"

HybridController::HybridController(PIDController* pid, MPCController* mpc, double threshold)
    : pid_(pid), mpc_(mpc), threshold_(threshold) {
}

double HybridController::computeControlInput(double error, double dt) {
    // Use PID for small errors, switch to MPC when error exceeds the threshold.
    if (std::abs(error) < threshold_) {
        return pid_->computeControlInput(error, dt);
    }
    else {
        return mpc_->computeControlInput(error, dt);
    }
}
