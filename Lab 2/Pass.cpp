#include "Pass.h"

Pass::Pass(const std::string& id, std::chrono::system_clock::time_point expiry)
    : id(id), expiry(expiry) {}

bool Pass::isExpired() const {
    return std::chrono::system_clock::now() > expiry;
}