#include <iostream>
#include <chrono>
#include "AccessControlSystem.h"
#include "Turnstile.h"

int main() {
    AccessControlSystem accessControlSystem;

    auto pass1 = accessControlSystem.issuePass("123", std::chrono::system_clock::now() + std::chrono::hours(1));
    auto pass2 = accessControlSystem.issuePass("456", std::chrono::system_clock::now() + std::chrono::hours(2));

    Turnstile turnstile;
    std::cout << "Passing through turnstile with pass1: " << accessControlSystem.openTurnstile(turnstile, "123") << std::endl;
    std::cout << "Passing through turnstile with pass2: " << accessControlSystem.openTurnstile(turnstile, "456") << std::endl;

    std::cout << "Pass1 is expired: " << pass1->isExpired() << std::endl;

    accessControlSystem.revokePass("123");
    std::cout << "Passing through turnstile with revoked pass1: " << accessControlSystem.openTurnstile(turnstile, "123") << std::endl;

    return 0;
}
