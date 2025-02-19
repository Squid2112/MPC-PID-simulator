#ifdef _WIN32
#include <windows.h>
#endif

#include "PIDController.h"
#include "MPCController.h"
#include "HybridController.h"
#include "ThermalSystem.h"
#include "Simulation.h"

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); // Set console output to UTF-8
#endif

    // Create individual controllers.
    auto pid = new PIDController(0.5, 0.1, 0.05);
    auto mpc = new MPCController(10);

    // Create a hybrid controller that selects between PID and MPC based on an error threshold.
    HybridController hybrid(pid, mpc, 2.0); // Use PID when error is within 2.0 units.

    // Create the thermal system model.
    // For example: initial temperature = 20°C, thermal capacity = 5000 J/°C, time constant = 600 s.
    ThermalSystem thermal(20.0, 5000, 600);

    // Set up the simulation: run for 1000 seconds with a time step of 1 second.
    Simulation sim(&hybrid, &thermal, 1000, 1);

    sim.run();

    // Clean up dynamically allocated controllers.
    delete pid;
    delete mpc;

    return 0;
}
