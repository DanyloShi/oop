#include <iostream>
#include "ShootingSession.h"
#include "FileSessionRepository.h"

using namespace std;

int main() {
    FileSessionRepository repository;
    ShootingSession session(repository);

    cout << "Loading previous session data..." << endl;
    session.loadSession();

    cout << "Starting new shooting session..." << endl;
    session.startSession();

    cout << "Saving session data..." << endl;
    session.saveSession();

    cout << "Session report:" << endl;
    session.printReport();

    return 0;
}
