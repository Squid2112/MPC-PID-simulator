#ifndef SIMULATION_H
#define SIMULATION_H

#include "thermal_system.h"
#include "pid_controller.h"
#include "mpc_controller.h"
#include "hybrid_controller.h"
#include <vector>

constexpr double PI = 3.14159265358979323846;

class Simulation {
public:
	Simulation(double initial_T);
	void run();
	void print_results() const;

private:
	ThermalSystem thermal_system;
	PIDController pid_controller;
	MPCController mpc_controller;
	HybridController hybrid_controller;
	std::vector<double> times;
	std::vector<double> temperatures;
	std::vector<double> ambient_temps;
	std::vector<double> control_inputs;

	double T_amb(double t) const;
};

#endif // SIMULATION_H