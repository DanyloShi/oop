#ifndef ACCESSCONTROLSYSTEM_H
#define ACCESSCONTROLSYSTEM_H

#include <vector>
#include "Pass.h"

class AccessControlSystem {
private:
    std::vector<Pass*> passes;

public:
    void addPass(Pass* pass);
    void printAllPassesInfo() const;
    void checkAllPassesValidity() const;
    ~AccessControlSystem();
};

#endif