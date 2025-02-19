#include "thermal_system.h"
#include "constants.h"

double ThermalSystem::update(double u, double T_amb) {
    double a = 1.0 - k * dt;
    double b = dt;
    double c = k * dt;
    // T_{n+1} = a T_n + b u + c T_amb
    current_T = a * current_T + b * u + c * T_amb;
    return current_T;
}