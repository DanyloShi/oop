#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

class Pass {
protected:               //Використання інкапсуляції
    string name;
    
public:
    string id;
    Pass(const string& name, const string& id) : name(name), id(id) {}             //Використання абстракції
    virtual ~Pass() {}
    virtual bool isValid() const = 0; 
    virtual void printInfo() const = 0; 
};

class TemporaryPass : public Pass {             //Використання наслідування
private:
    string expirationDate;
public:
    TemporaryPass(const string& name, const string& id, const string& expirationDate)
        : Pass(name, id), expirationDate(expirationDate) {}

    bool isValid() const override {
        time_t currentTime = time(nullptr);
        tm* currentDate = localtime(&currentTime);

        tm expiration = {};
        istringstream ss(expirationDate);

        int day, month, year;
        char delimiter;
        ss >> day >> delimiter >> month >> delimiter >> year;

        expiration.tm_mday = day;
        expiration.tm_mon = month - 1;
        expiration.tm_year = year - 1900;

        if (difftime(mktime(currentDate), mktime(&expiration)) > 0) {
            return false;
        } else {
            return true;
        }
    }



    void printInfo() const override {               //Використання поліморфізму
        cout << "Temporary Pass - Name: " << name << ", ID: " << id << ", Expiration Date: " << expirationDate << endl;
    }
};

class AccessControlSystem {
private:
    vector<Pass*> passes;
public:
    void addPass(Pass* pass) {
        passes.push_back(pass);
    }

    void printAllPassesInfo() const {
        for (const auto& pass : passes) {
            pass->printInfo();
        }
    }

    void checkAllPassesValidity() const {
        for (const auto& pass : passes) {
            if (pass->isValid()) {
                cout << "Pass with ID: " << pass->id << " is valid." << endl;
            } else {
                cout << "Pass with ID: " << pass->id << " is invalid." << endl;
            }
        }
    }
};

int main() {
    AccessControlSystem system;

    system.addPass(new TemporaryPass("Name Surname", "1234", "10.03.2024"));
    system.addPass(new TemporaryPass("Name Surname 2", "5678", "20.03.2025"));

    system.printAllPassesInfo();

    system.checkAllPassesValidity();


    // for (const auto& pass : system) {
    //     delete pass;
    // }

    return 0;
}
