#include <iomanip>
#include "simulation.h"
#include <iostream>
#include <cmath>
#include <numbers>

Simulation::Simulation(double initial_T)
	: thermal_system(initial_T),
	  pid_controller(),
	  mpc_controller(),
	  hybrid_controller(pid_controller, mpc_controller) {
	double initial_error = T_setpoint - initial_T;
	pid_controller.set_initial_error(initial_error);
}

double Simulation::T_amb(double t) const {
	return T_avg + A * sin(2.0 * PI * t / P);
}

void Simulation::run() {
	double current_time = 0.0;
	thermal_system = ThermalSystem(thermal_system.get_current_T()); // Reset to initial

	for (int step = 0; step < num_steps; ++step) {
		double current_T = thermal_system.get_current_T();
		times.push_back(current_time);
		temperatures.push_back(current_T);
		ambient_temps.push_back(T_amb(current_time));

		// Compute future T_amb for MPC (next N steps)
		std::vector<double> future_T_amb;
		for (int i = 0; i < N; ++i) {
			double future_time = current_time + i * dt;
			future_T_amb.push_back(T_amb(future_time));
		}

		// Compute control input
		double u = hybrid_controller.compute_u(current_T, future_T_amb);
		control_inputs.push_back(u);

		// Update temperature
		double current_T_amb = T_amb(current_time);
		thermal_system.update(u, current_T_amb);

		current_time += dt;
	}
}

void Simulation::print_results() const {
	// Headers, right-justified
	std::cout << std::right << std::setw(10) << "Time" << " | "
			  << std::right << std::setw(16) << "Temperature (°C)" << " | "
			  << std::right << std::setw(16) << "Ambient Temp (°C)" << " | "
			  << std::right << std::setw(16) << "Control Input (°C/s)" << std::endl;

	// Separator
	std::cout << std::string(10, '-') << " | "
			  << std::string(16, '-') << " | "
			  << std::string(16, '-') << " | "
			  << std::string(16, '-') << std::endl;

	// Data, right-justified with appropriate formats
	for (size_t i = 0; i < times.size(); ++i) {
		std::cout << std::right << std::setw(10) << static_cast<int>(times[i]) << " | "
				  << std::right << std::setw(16) << std::fixed << std::setprecision(4) << temperatures[i] << " | "
				  << std::right << std::setw(16) << std::fixed << std::setprecision(4) << ambient_temps[i] << " | "
				  << std::right << std::setw(16) << std::scientific << std::setprecision(5) << control_inputs[i] << std::endl;
	}
}