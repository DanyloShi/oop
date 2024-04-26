#ifndef TEMPORARYPASS_H
#define TEMPORARYPASS_H

#include "Pass.h"
#include <ctime>
#include <sstream>

class TemporaryPass : public Pass {
private:
    std::string expirationDate;

public:
    TemporaryPass(const std::string& name, const std::string& id, const std::string& expirationDate);
    bool isValid() const override;
    void printInfo() const override;
};

#endif