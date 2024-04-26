#include "AccessControlSystem.h"

AccessControlSystem::AccessControlSystem() {}

bool AccessControlSystem::openTurnstile(Turnstile& turnstile, const std::string& passId) {
    Pass* pass = nullptr;
    auto it = passes.find(passId);
    if (it != passes.end()) {
        pass = it->second;
    }
    return turnstile.passThrough(pass);
}

Pass* AccessControlSystem::issuePass(const std::string& id, std::chrono::system_clock::time_point expiry) {
    Pass* new_pass = new Pass(id, expiry);
    passes[id] = new_pass;
    return new_pass;
}

void AccessControlSystem::revokePass(const std::string& id) {
    auto it = passes.find(id);
    if (it != passes end()) {
        delete it->second;
        passes.erase(it);
    }
}