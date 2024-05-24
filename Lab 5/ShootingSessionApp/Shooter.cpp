#include "Shooter.h"

Shooter::Shooter(const std::string& name, const std::string& sessionTime) : name(name), sessionTime(sessionTime) {}

void Shooter::addTarget(char target, const std::string& status) {
    targets.push_back({target, status});
}

const std::string& Shooter::getName() const {
    return name;
}

const std::string& Shooter::getSessionTime() const {
    return sessionTime;
}

const std::vector<ShotRecord>& Shooter::getTargets() const {
    return targets;
}
