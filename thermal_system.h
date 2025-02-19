#ifndef THERMAL_SYSTEM_H
#define THERMAL_SYSTEM_H

#include <cmath>

class ThermalSystem {
public:
    ThermalSystem(double initial_T) : current_T(initial_T) {}
    double update(double u, double T_amb);
    double get_current_T() const { return current_T; }

private:
    double current_T;
};

#endif // THERMAL_SYSTEM_H