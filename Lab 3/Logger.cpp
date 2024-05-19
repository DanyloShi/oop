#include "ILogger.h"
#include <iostream>

using namespace std;

class Logger : public ILogger {
public:
    void log(const string& message) override {
        cout << message << endl;
    }
};