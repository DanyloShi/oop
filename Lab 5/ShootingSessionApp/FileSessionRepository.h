#pragma once
#include "ISessionRepository.h"

class FileSessionRepository : public ISessionRepository {
public:
    void save(const std::vector<Shooter>& shooters) override;
    std::vector<Shooter> load() override;
};
