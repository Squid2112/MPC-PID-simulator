#include "ThermalSystem.h"

ThermalSystem::ThermalSystem(double initialTemp, double thermalCapacity, double timeConstant)
    : temperature_(initialTemp), capacity_(thermalCapacity), timeConstant_(timeConstant) {
}

void ThermalSystem::update(double controlInput, double dt) {
    // Simple first-order thermal model.
    // For demonstration, assume ambient temperature = 0.
    double dT = (controlInput - temperature_) / timeConstant_;
    temperature_ += dT * dt;
}

double ThermalSystem::getOutput() const {
    return temperature_;
}
