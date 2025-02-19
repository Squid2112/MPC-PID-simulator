#ifndef MPCCONTROLLER_H
#define MPCCONTROLLER_H

#include "IController.h"

class MPCController : public IController {
public:
    explicit MPCController(int horizon);
    virtual double computeControlInput(double error, double dt) override;
private:
    int horizon_;
};

#endif // MPCCONTROLLER_H
