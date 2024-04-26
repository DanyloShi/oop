#include "AccessControlSystem.h"
#include "TemporaryPass.h"

int main() {
    AccessControlSystem system;

    system.addPass(new TemporaryPass("Name Surname", "1234", "10.03.2024"));
    system.addPass(new TemporaryPass("Name Surname 2", "5678", "20.03.2025"));

    system.printAllPassesInfo();

    system.checkAllPassesValidity();

    return 0;
}
