#ifndef ICONTROLLER_H
#define ICONTROLLER_H

// Abstract interface for all controllers.
class IController {
public:
    virtual ~IController() = default;
    // Compute the control input given the current error and time step.
    virtual double computeControlInput(double error, double dt) = 0;
};

#endif // ICONTROLLER_H
