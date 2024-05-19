#include "IDatabase.h"
#include <unordered_map>
#include <string>

using namespace std;

class Database : public IDatabase {
public:
    void savePass(const string& user, const string& room) override {
        passes_[user].insert(room);
    }

    void deletePass(const string& user, const string& room) override {
        passes_[user].erase(room);
    }

    bool hasPass(const string& user, const string& room) override {
        return passes_[user].find(room) != passes_[user].end();
    }

private:
    unordered_map<string, unordered_set<string>> passes_;
};