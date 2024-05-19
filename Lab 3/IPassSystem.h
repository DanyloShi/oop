#ifndef IPASS_SYSTEM_H
#define IPASS_SYSTEM_H

using namespace std;

class IPassSystem {
public:
    virtual void issuePass(const string& user, const string& room) = 0;
    virtual void revokePass(const string& user, const string& room) = 0;
    virtual bool canEnter(const string& user, const string& room) = 0;
    virtual ~IPassSystem() = default;
};

#endif