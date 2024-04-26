#include "TemporaryPass.h"
#include <iostream>

TemporaryPass::TemporaryPass(const std::string& name, const std::string& id, const std::string& expirationDate)
    : Pass(name, id), expirationDate(expirationDate) {}

bool TemporaryPass::isValid() const {
    time_t currentTime = time(nullptr);
    tm* currentDate = localtime(&currentTime);

    tm expiration = {};
    std::istringstream ss(expirationDate);

    int day, month, year;
    char delimiter;
    ss >> day >> delimiter >> month >> delimiter >> year;

    expiration.tm_mday = day;
    expiration.tm_mon = month - 1;
    expiration.tm_year = year - 1900;

    return difftime(mktime(currentDate), mktime(&expiration)) <= 0;
}

void TemporaryPass::printInfo() const {
    std::cout << "Temporary Pass - Name: " << name << ", ID: " << id 
              << ", Expiration Date: " << expirationDate << std::endl;
}