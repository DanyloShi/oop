#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>

using namespace std;

// Клас, що представляє пропуск
class Pass {
public:
    Pass(string id, chrono::system_clock::time_point expiry)
        : id(id), expiry(expiry) {}

    bool isExpired() const {
        return chrono::system_clock::now() > expiry;
    }

private:
    string id;
    chrono::system_clock::time_point expiry;
};

// Клас, що представляє турнікет
class Turnstile {
public:
    Turnstile() : pass(nullptr) {}

    // Метод для пропуску людини
    bool passThrough(Pass* pass) {
        if (pass && !pass->isExpired()) {
            this->pass = pass;
            return true;
        }
        return false;
    }

    // Метод для видачі пропуску
    Pass* issuePass(const string& id, chrono::system_clock::time_point expiry) {
        Pass* pass = new Pass(id, expiry);
        passes[id] = pass;
        return pass;
    }

    // Метод для відкликання пропуску
    void revokePass(const string& id) {
        auto it = passes.find(id);
        if (it != passes.end()) {
            delete it->second;
            passes.erase(it);
        }
    }

private:
    Pass* pass;
    unordered_map<string, Pass*> passes;
};

// Клас, що представляє автоматизовану систему пропуску
class AccessControlSystem {
public:
    AccessControlSystem() {}

    // Метод для відкриття турнікету та пропуску через нього
    bool openTurnstile(Turnstile& turnstile, const string& passId) {
        Pass* pass = nullptr;
        auto it = passes.find(passId);
        if (it != passes.end()) {
            pass = it->second;
        }
        return turnstile.passThrough(pass);
    }

    // Метод для видачі пропуску
    Pass* issuePass(const string& id, chrono::system_clock::time_point expiry) {
        Pass* pass = new Pass(id, expiry);
        passes[id] = pass;
        return pass;
    }

    // Метод для відкликання пропуску
    void revokePass(const string& id) {
        auto it = passes.find(id);
        if (it != passes.end()) {
            delete it->second;
            passes.erase(it);
        }
    }

private:
    unordered_map<string, Pass*> passes;
};

int main() {
    AccessControlSystem accessControlSystem;

    // Видача пропусків
    auto pass1 = accessControlSystem.issuePass("123", chrono::system_clock::now() + chrono::hours(1));
    auto pass2 = accessControlSystem.issuePass("456", chrono::system_clock::now() + chrono::hours(2));

    // Відкриття турнікету та пропуск через нього
    Turnstile turnstile;
    cout << "Passing through turnstile with pass1: " << accessControlSystem.openTurnstile(turnstile, "123") << endl;
    cout << "Passing through turnstile with pass2: " << accessControlSystem.openTurnstile(turnstile, "456") << endl;

    // Перевірка вичерпання строку дії пропуску
    cout << "Pass1 is expired: " << pass1->isExpired() << endl;

    // Відкликання пропуску
    accessControlSystem.revokePass("123");
    cout << "Passing through turnstile with revoked pass1: " << accessControlSystem.openTurnstile(turnstile, "123") << endl;

    return 0;
}