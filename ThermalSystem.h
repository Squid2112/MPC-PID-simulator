#ifndef THERMALSYSTEM_H
#define THERMALSYSTEM_H

#include "ISystemModel.h"

class ThermalSystem : public ISystemModel {
public:
    ThermalSystem(double initialTemp, double thermalCapacity, double timeConstant);
    virtual void update(double controlInput, double dt) override;
    virtual double getOutput() const override;
private:
    double temperature_;
    double capacity_;
    double timeConstant_;
};

#endif // THERMALSYSTEM_H
