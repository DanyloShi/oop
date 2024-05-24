#include "FileSessionRepository.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void FileSessionRepository::save(const vector<Shooter>& shooters) {
    ofstream file("session_data.txt");
    for (const auto& shooter : shooters) {
        file << shooter.getName() << endl;
        file << shooter.getSessionTime() << endl;
        for (const auto& target : shooter.getTargets()) {
            file << target.target << " " << target.status << endl;
        }
        file << "---" << endl;
    }
}

vector<Shooter> FileSessionRepository::load() {
    vector<Shooter> shooters;
    ifstream file("session_data.txt");
    string line;
    while (getline(file, line)) {
        if (line == "---") continue;
        string shooterName = line;
        getline(file, line);
        string sessionTime = line;
        Shooter shooter(shooterName, sessionTime);
        while (getline(file, line) && line != "---") {
            istringstream iss(line);
            char target;
            string status;
            iss >> target;
            iss.ignore(1, ' ');
            getline(iss, status);
            shooter.addTarget(target, status);
        }
        shooters.push_back(shooter);
    }
    return shooters;
}
