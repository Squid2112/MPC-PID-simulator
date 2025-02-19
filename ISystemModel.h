#ifndef ISYSTEMMODEL_H
#define ISYSTEMMODEL_H

// Abstract interface for the physical system model.
class ISystemModel {
public:
    virtual ~ISystemModel() = default;
    // Update the system's state given a control input and time step.
    virtual void update(double controlInput, double dt) = 0;
    // Retrieve the current output (e.g., temperature).
    virtual double getOutput() const = 0;
};

#endif // ISYSTEMMODEL_H
