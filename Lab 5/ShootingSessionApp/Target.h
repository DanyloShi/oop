#pragma once
#include <string>

class Target {
public:
    Target(int id, const std::string& description);
    int getId() const;
    const std::string& getDescription() const;
private:
    int id;
    std::string description;
};
