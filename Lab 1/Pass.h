#ifndef PASS_H
#define PASS_H

#include <string>

class Pass {
protected:
    std::string name;
    
public:
    std::string id;
    Pass(const std::string& name, const std::string& id);
    virtual ~Pass();
    virtual bool isValid() const = 0;
    virtual void printInfo() const = 0;
};

#endif