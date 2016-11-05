#ifndef CONFIGURABLEEVENTLISTENER_HPP
#define CONFIGURABLEEVENTLISTENER_HPP

#include "gtest/gtest.h"

using namespace testing;

class ConfigurableEventListener : public TestEventListener {
protected:
    TestEventListener* eventListener;

public:
    bool showTestCases;
    bool showTestNames;
    bool showSuccesses;
    bool showInlineFailures;  // Show failures as they occur
    bool showEnvironment;  // Show environment setup

    explicit ConfigurableEventListener(TestEventListener* theEventListener)
        : eventListener(theEventListener)
    {
        showTestCases = true;
        showTestNames = true;
        showSuccesses = true;
        showInlineFailures = true;
        showEnvironment = true;
    }

    virtual ~ConfigurableEventListener() {
        delete eventListener;
    }

    virtual void OnTestProgramStart(const UnitTest& unit_test) {
        eventListener->OnTestProgramStart(unit_test);
    }

    virtual void OnTestIterationStart(const UnitTest& unit_test, int iteration) {
        eventListener->OnTestIterationStart(unit_test, iteration);
    }

    virtual void OnEnvironmentsSetUpStart(const UnitTest& unit_test) {
        if(showEnvironment) {
            eventListener->OnEnvironmentsSetUpStart(unit_test);
        }
    }

    virtual void OnEnvironmentsSetUpEnd(const UnitTest& unit_test) {
        if(showEnvironment) {
            eventListener->OnEnvironmentsSetUpEnd(unit_test);
        }
    }

    virtual void OnTestCaseStart(const TestCase& test_case) {
        if(showTestCases) {
            eventListener->OnTestCaseStart(test_case);
        }
    }

    virtual void OnTestStart(const TestInfo& test_info) {
        if(showTestNames) {
            eventListener->OnTestStart(test_info);
        }
    }

    virtual void OnTestPartResult(const TestPartResult& result) {
        eventListener->OnTestPartResult(result);
    }

    virtual void OnTestEnd(const TestInfo& test_info) {
        if((showInlineFailures && test_info.result()->Failed()) || (showSuccesses && !test_info.result()->Failed())) {
            eventListener->OnTestEnd(test_info);
        }
    }

    virtual void OnTestCaseEnd(const TestCase& test_case) {
        if(showTestCases) {
            eventListener->OnTestCaseEnd(test_case);
        }
    }

    virtual void OnEnvironmentsTearDownStart(const UnitTest& unit_test) {
        if(showEnvironment) {
            eventListener->OnEnvironmentsTearDownStart(unit_test);
        }
    }

    virtual void OnEnvironmentsTearDownEnd(const UnitTest& unit_test) {
        if(showEnvironment) {
            eventListener->OnEnvironmentsTearDownEnd(unit_test);
        }
    }

    virtual void OnTestIterationEnd(const UnitTest& unit_test, int iteration) {
        eventListener->OnTestIterationEnd(unit_test, iteration);
    }

    virtual void OnTestProgramEnd(const UnitTest& unit_test) {
        eventListener->OnTestProgramEnd(unit_test);
    }

};

#endif
