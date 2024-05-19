#ifndef ILOGGER_H
#define ILOGGER_H

class ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

#endif