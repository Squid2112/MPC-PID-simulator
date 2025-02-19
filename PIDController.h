#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "IController.h"

class PIDController : public IController {
public:
    PIDController(double kp, double ki, double kd);
    virtual double computeControlInput(double error, double dt) override;
private:
    double kp_;
    double ki_;
    double kd_;
    double integral_;
    double previousError_;
};

#endif // PIDCONTROLLER_H
