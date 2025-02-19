#include "Simulation.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

// Constructor definition matching the declaration in Simulation.h.
Simulation::Simulation(IController* controller, ISystemModel* model, double simulationTime, double dt)
    : controller_(controller), model_(model), simulationTime_(simulationTime), dt_(dt)
{
    // You can add additional initialization code here if needed.
}

void Simulation::run() {
    double currentTime = 0.0;
    const double setpoint = 25.0; // Desired temperature in °C
    double totalError = 0.0;
    double maxError = 0.0;
    int count = 0;

    // Open an output file for CSV logging.
    std::ofstream outFile("simulation_output.csv");
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file.\n";
        return;
    }

    // Print headers to console.
    std::cout << std::setw(12) << "Time (s)"
        << std::setw(20) << "Temp (°C)"
        << std::setw(12) << "Error"
        << std::setw(20) << "Control Input" << std::endl;
    std::cout << std::string(64, '-') << std::endl;

    // Write CSV header.
    outFile << "Time (s),Temp (°C),Error,Control Input\n";

    // Simulation loop.
    while (currentTime < simulationTime_) {
        double currentTemp = model_->getOutput();
        double error = setpoint - currentTemp;
        double controlInput = controller_->computeControlInput(error, dt_);
        model_->update(controlInput, dt_);

        // Print simulation data in columns.
        std::cout << std::setw(12) << currentTime
            << std::setw(20) << std::fixed << std::setprecision(4) << currentTemp
            << std::setw(12) << error
            << std::setw(20) << controlInput << std::endl;

        // Write data to CSV.
        outFile << currentTime << ","
            << std::fixed << std::setprecision(4) << currentTemp << ","
            << error << ","
            << controlInput << "\n";

        // Update summary statistics.
        totalError += std::abs(error);
        if (std::abs(error) > maxError)
            maxError = std::abs(error);
        count++;

        currentTime += dt_;
    }
    outFile.close();

    // Compute and output summary statistics.
    double avgError = (count > 0) ? totalError / count : 0.0;
    std::cout << "\nSimulation Summary:\n";
    std::cout << "Average Absolute Error: " << avgError << "\n";
    std::cout << "Maximum Absolute Error: " << maxError << "\n";
}
