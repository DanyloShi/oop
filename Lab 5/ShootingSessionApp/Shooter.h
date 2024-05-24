#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;

struct ShotRecord {
    char target;
    string status;
};

class Shooter {
public:
    Shooter(const string& name, const string& sessionTime);
    void addTarget(char target, const string& status);
    const string& getName() const;
    const string& getSessionTime() const;
    const vector<ShotRecord>& getTargets() const;
private:
    string name;
    string sessionTime;
    vector<ShotRecord> targets;
};
