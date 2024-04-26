#include "AccessControlSystem.h"
#include <iostream>

void AccessControlSystem::addPass(Pass* pass) {
    passes.push_back(pass);
}

void AccessControlSystem::printAllPassesInfo() const {
    for (const auto& pass : passes) {
        pass->printInfo();
    }
}

void AccessControlSystem::checkAllPassesValidity() const {
    for (const auto& pass : passes) {
        if (pass->isValid()) {
            std::cout << "Pass with ID: " << pass->id << " is valid." << std::endl;
        } else {
            std::cout << "Pass with ID: " << pass->id << " is invalid." << std::endl;
        }
    }
}

AccessControlSystem::~AccessControlSystem() {
    for (auto& pass : passes) {
        delete pass;
    }
}