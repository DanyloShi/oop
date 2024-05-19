#include "IPassSystem.h"
#include "ILogger.h"
#include "IDatabase.h"
#include <iostream>

using namespace std;

class PassSystem : public IPassSystem {
public:
    PassSystem(shared_ptr<ILogger> logger, shared_ptr<IDatabase> database)
        : logger_(logger), database_(database) {}

    void issuePass(const string& user, const string& room) override {
        if (!database_->hasPass(user, room)) {
            database_->savePass(user, room);
            logger_->log("Issued pass to " + user + " for room " + room);
        } else {
            logger_->log(user + " already has a pass for room " + room);
        }
    }

    void revokePass(const string& user, const string& room) override {
        if (database_->hasPass(user, room)) {
            database_->deletePass(user, room);
            logger_->log("Revoked pass from " + user + " for room " + room);
        } else {
            logger_->log(user + " does not have a pass for room " + room);
        }
    }

    bool canEnter(const string& user, const string& room) override {
        bool allowed = database_->hasPass(user, room);
        if (allowed) {
            logger_->log(user + " entered room " + room);
        } else {
            logger_->log(user + " denied entry to room " + room);
        }
        return allowed;
    }

private:
    shared_ptr<ILogger> logger_;
    shared_ptr<IDatabase> database_;
};