#include "TestFramework.h"
#include "PassSystem.cpp"
#include "Logger.cpp"
#include "Database.cpp"

using namespace std;

class PassSystemTest {
public:
    static void testIssuePass() {
        // Arrange
        auto logger = make_shared<Logger>();
        auto database = make_shared<Database>();
        PassSystem passSystem(logger, database);
        string user = "Alice";
        string room = "Room1";

        // Act
        passSystem.issuePass(user, room);

        // Assert
        TestFramework::assertTrue(database->hasPass(user, room), "testIssuePass");
    }

    static void testRevokePass() {
        // Arrange
        auto logger = make_shared<Logger>();
        auto database = make_shared<Database>();
        PassSystem passSystem(logger, database);
        string user = "Alex";
        string room = "Room1";
        passSystem.issuePass(user, room);

        // Act
        passSystem.revokePass(user, room);

        // Assert
        TestFramework::assertFalse(database->hasPass(user, room), "testRevokePass");
    }

    static void testCanEnter() {
        // Arrange
        auto logger = make_shared<Logger>();
        auto database = make_shared<Database>();
        PassSystem passSystem(logger, database);
        string user = "Alice";
        string room = "Room1";
        passSystem.issuePass(user, room);

        // Act & Assert
        TestFramework::assertTrue(passSystem.canEnter(user, room), "testCanEnter - can enter");
        passSystem.revokePass(user, room);
        TestFramework::assertFalse(passSystem.canEnter(user, room), "testCanEnter - cannot enter");
    }
};