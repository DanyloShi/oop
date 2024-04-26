#pragma once
#include <string>
#include <chrono>

class Pass {
public:
    Pass(const std::string& id, std::chrono::system_clock::time_point expiry);

    bool isExpired() const;

private:
    std::string id;
    std::chrono::system_clock::time_point expiry;
};