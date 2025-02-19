#ifndef HYBRIDCONTROLLER_H
#define HYBRIDCONTROLLER_H

#include "IController.h"
#include "PIDController.h"
#include "MPCController.h"
#include <cmath>

class HybridController : public IController {
public:
    HybridController(PIDController* pid, MPCController* mpc, double threshold);
    virtual double computeControlInput(double error, double dt) override;
private:
    PIDController* pid_;
    MPCController* mpc_;
    double threshold_;
};

#endif // HYBRIDCONTROLLER_H
