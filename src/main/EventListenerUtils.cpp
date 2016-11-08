#include "EventListenerUtils.h"

void EventListenerUtils::setDefaultEventListener() {
    // Remove the default listener
    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();
    auto defaultPrinter = listeners.Release(listeners.default_result_printer());

    ConfigurableEventListener *listener = new ConfigurableEventListener(defaultPrinter);
    listener->showEnvironment = DefaultEventListener::SHOW_ENV;
    listener->showTestCases = DefaultEventListener::SHOW_TEST_CASES;
    listener->showTestNames = DefaultEventListener::SHOW_TEST_NAMES;
    listener->showSuccesses = DefaultEventListener::SHOW_SUCCESSES;
    listener->showInlineFailures = DefaultEventListener::SHOW_INLINE_FAILURES;

    listeners.Append(listener);
}
