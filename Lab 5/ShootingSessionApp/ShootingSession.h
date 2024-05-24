#pragma once
#include <vector>
#include "Shooter.h"
#include "ISessionRepository.h"

class ShootingSession {
public:
    ShootingSession(ISessionRepository& repository);
    void addShooter(const Shooter& shooter);
    void recordHit(const std::string& shooterName, char target, const std::string& status);
    void saveSession();
    void loadSession();
    void printReport() const;
    void printShooterStats(const std::string& shooterName) const;
    void startSession();
private:
    std::vector<Shooter> shooters;
    ISessionRepository& repository;
    std::string getCurrentTime() const;
};
