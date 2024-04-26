#include "Turnstile.h"

Turnstile::Turnstile() : pass(nullptr) {}

bool Turnstile::passThrough(Pass* pass) {
    if (pass && !pass->isExpired()) {
        this->pass = pass;
        return true;
    }
    return false;
}

Pass* Turnstile::issuePass(const std::string& id, std::chrono::system_clock::time_point expiry) {
    Pass* new_pass = new Pass(id, expiry);
    passes[id] = new_pass;
    return new_pass;
}

void Turnstile::revokePass(const std::string& id) {
    auto it = passes.find(id);
    if (it != passes.end()) {
        delete it->second;
        passes.erase(it);
    }
}