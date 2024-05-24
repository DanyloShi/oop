#pragma once
#include <vector>
#include "Shooter.h"

class ISessionRepository {
public:
    virtual ~ISessionRepository() = default;
    virtual void save(const std::vector<Shooter>& shooters) = 0;
    virtual std::vector<Shooter> load() = 0;
};
