#include "TestListenerUtils.h"

using namespace TestListenerUtils;

Listener* TestListenerUtils::createEventListener() {
    Listener* base = getCurrentListener();
    ConfigurableEventListener* configurableListener = new ConfigurableEventListener(base);
    Listener* listener = configurableListener;

    configurableListener->showEnvironment = true;
    configurableListener->showTestCases = false;
    configurableListener->showTestNames = false;
    configurableListener->showSuccesses = false;
    configurableListener->showInlineFailures = true;

    return listener;
}

Listener* TestListenerUtils::getCurrentListener() {
    Listeners& listeners = getListeners();
    Listener* base = listeners.default_result_printer();

    return base;
}

Listeners& TestListenerUtils::getListeners() {
    return testing::UnitTest::GetInstance()->listeners();
}

void TestListenerUtils::setEventListener(Listener* listener) {
    Listeners& listeners = getListeners();

    listeners.Release(listeners.default_result_printer());

    listeners.Append(listener);
}
