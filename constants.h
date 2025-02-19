#ifndef CONSTANTS_H
#define CONSTANTS_H

const double dt = 60.0; // seconds
const double total_time = 48 * 3600.0; // seconds
const int num_steps = static_cast<int>(total_time / dt) + 1; // +1 to include t=0
const double T_avg = 20.0; // Celsius
const double A = 10.0; // Celsius
const double P = 24 * 3600.0; // seconds
const double k = 0.01; // 1/s
const double T_setpoint = 25.0; // Celsius
// PID gains
const double Kp = 0.5; // 1/s
const double Ki = 0.1; // 1/s^2
const double Kd = 0.05; // dimensionless
// MPC parameters
const int N = 10; // prediction horizon in steps
const double lambda = 0.1; // control weight
// Hybrid controller threshold
const double error_threshold = 2.0; // Celsius

#endif // CONSTANTS_H