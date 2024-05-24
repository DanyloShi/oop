#include "ShootingSession.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

ShootingSession::ShootingSession(ISessionRepository& repository) : repository(repository) {}

void ShootingSession::addShooter(const Shooter& shooter) {
    shooters.push_back(shooter);
}

void ShootingSession::recordHit(const string& shooterName, char target, const string& status) {
    auto it = find_if(shooters.begin(), shooters.end(),
        [&shooterName](const Shooter& s) { return s.getName() == shooterName; });
    
    if (it != shooters.end()) {
        it->addTarget(target, status);
    } else {
        Shooter newShooter(shooterName, getCurrentTime());
        newShooter.addTarget(target, status);
        shooters.push_back(newShooter);
    }
}

void ShootingSession::saveSession() {
    repository.save(shooters);
}

void ShootingSession::loadSession() {
    shooters = repository.load();
}

void ShootingSession::printReport() const {
    for (const auto& shooter : shooters) {
        cout << "Shooter: " << shooter.getName() << endl;
        cout << "  Session Time: " << shooter.getSessionTime() << endl;
        for (const auto& target : shooter.getTargets()) {
            cout << "  Target: " << target.target << ", Status: " << target.status << endl;
        }
    }
}

void ShootingSession::printShooterStats(const string& shooterName) const {
    auto it = find_if(shooters.begin(), shooters.end(),
        [&shooterName](const Shooter& s) { return s.getName() == shooterName; });

    if (it != shooters.end()) {
        cout << "Shooter: " << it->getName() << endl;
        cout << "  Session Time: " << it->getSessionTime() << endl;
        vector<char> targets = {'A', 'B', 'C', 'D', 'E', 'F'};
        for (const auto& target : targets) {
            string status = "Не стріляв";
            auto targetIt = find_if(it->getTargets().begin(), it->getTargets().end(),
                [&target](const ShotRecord& sr) { return sr.target == target; });
            if (targetIt != it->getTargets().end()) {
                status = targetIt->status;
            }
            cout << "  Target: " << target << ", Status: " << status << endl;
        }
    } else {
        cout << "Shooter not found: " << shooterName << endl;
    }
}

void ShootingSession::startSession() {
    string command;
    while (true) {
        cout << "Enter command (hit, stats, exit): ";
        cin >> command;
        if (command == "exit") break;
        else if (command == "hit") {
            string shooterName;
            cout << "Enter shooter name: ";
            cin >> shooterName;
            vector<char> targets = {'A', 'B', 'C', 'D', 'E', 'F'};
            for (const auto& target : targets) {
                int hit;
                cout << "Did shooter hit target " << target << "? (1 for yes, 0 for no, -1 for not shot): ";
                cin >> hit;
                if (hit == 1) {
                    recordHit(shooterName, target, "Влучив");
                } else if (hit == 0) {
                    recordHit(shooterName, target, "Промах");
                } else if (hit == -1) {
                    recordHit(shooterName, target, "Не стріляв");
                }
            }
        } else if (command == "stats") {
            string shooterName;
            cout << "Enter shooter name: ";
            cin >> shooterName;
            printShooterStats(shooterName);
        } else {
            cout << "Invalid command." << endl;
        }
    }
}

string ShootingSession::getCurrentTime() const {
    time_t now = time(nullptr);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}
