#include "ConfigurableEventListener.h"

int main(int argc, char **argv) {
    // initialize
    ::testing::InitGoogleTest(&argc, argv);

    // remove the default listener
    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();
    auto default_printer = listeners.Release(listeners.default_result_printer());

    // add our listener, by default everything is on (the same as using the default listener)
    // here I am turning everything off so I only see the 3 lines for the result
    // (plus any failures at the end), like:

    // [==========] Running 149 tests from 53 test cases.
    // [==========] 149 tests from 53 test cases ran. (1 ms total)
    // [  PASSED  ] 149 tests.

    ConfigurableEventListener *listener = new ConfigurableEventListener(default_printer);
    listener->showEnvironment = false;
    listener->showTestCases = false;
    listener->showTestNames = false;
    listener->showSuccesses = false;
    listener->showInlineFailures = false;
    listeners.Append(listener);

    // run
    return RUN_ALL_TESTS();
}
