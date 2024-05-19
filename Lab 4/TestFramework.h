#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <iostream>
#include <string>

class TestFramework {
public:
    static void assertTrue(bool condition, const std::string& testName) {
        if (condition) {
            std::cout << "[PASS] " << testName << std::endl;
        } else {
            std::cout << "[FAIL] " << testName << std::endl;
        }
    }

    static void assertFalse(bool condition, const std::string& testName) {
        assertTrue(!condition, testName);
    }

    static void runTests();
};

#endif