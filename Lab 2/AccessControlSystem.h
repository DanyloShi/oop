#pragma once
#include <string>
#include <unordered_map>
#include "Pass.h"
#include "Turnstile.h"

class AccessControlSystem {
public:
    AccessControlSystem();

    bool openTurnstile(Turnstile& turnstile, const std::string& passId);
    Pass* issuePass(const std::string& id, std::chrono::system_clock::time_point expiry);
    void revokePass(const std::string& id);

private:
    std::unordered_map<std::string, Pass*> passes;
};