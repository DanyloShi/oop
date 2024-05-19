#include <boost/di.hpp>
#include "IPassSystem.h"
#include "ILogger.h"
#include "IDatabase.h"
#include "PassSystem.cpp"
#include "Logger.cpp"
#include "Database.cpp"

namespace di = boost::di;

int main() {
    auto injector = di::make_injector(
        di::bind<ILogger>().to<Logger>(),
        di::bind<IDatabase>().to<Database>(),
        di::bind<IPassSystem>().to<PassSystem>()
    );

    auto passSystem = injector.create<std::shared_ptr<IPassSystem>>();

    passSystem->issuePass("Alex", "Room1");
    passSystem->canEnter("Alex", "Room1");
    passSystem->revokePass("Alex", "Room1");
    passSystem->canEnter("Alex", "Room1");

    return 0;
}
