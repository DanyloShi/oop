#ifndef IDATABASE_H
#define IDATABASE_H

#include <string>

using namespace std;

class IDatabase {
public:
    virtual void savePass(const string& user, const string& room) = 0;
    virtual void deletePass(const string& user, const string& room) = 0;
    virtual bool hasPass(const string& user, const string& room) = 0;
    virtual ~IDatabase() = default;
};

#endif