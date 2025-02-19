#include "PIDController.h"

PIDController::PIDController(double kp, double ki, double kd)
    : kp_(kp), ki_(ki), kd_(kd), integral_(0.0), previousError_(0.0) {
}

double PIDController::computeControlInput(double error, double dt) {
    integral_ += error * dt;
    double derivative = (error - previousError_) / dt;
    previousError_ = error;
    return kp_ * error + ki_ * integral_ + kd_ * derivative;
}
