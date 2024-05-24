#include "Target.h"

Target::Target(int id, const std::string& description) : id(id), description(description) {}

int Target::getId() const {
    return id;
}

const std::string& Target::getDescription() const {
    return description;
}
