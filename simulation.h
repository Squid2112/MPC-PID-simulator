#ifndef SIMULATION_H
#define SIMULATION_H

#include "IController.h"
#include "ISystemModel.h"

class Simulation {
public:
    // Constructor declaration.
    Simulation(IController* controller, ISystemModel* model, double simulationTime, double dt);

    // Run the simulation.
    void run();

private:
    IController* controller_;
    ISystemModel* model_;
    double simulationTime_;
    double dt_;
};

#endif // SIMULATION_H
