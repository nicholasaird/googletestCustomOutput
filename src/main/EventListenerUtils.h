#ifndef EVENTLISTENERUTILS_HPP
#define EVENTLISTENERUTILS_HPP

#include "gtest/gtest.h"

#include "ConfigurableEventListener.h"

namespace DefaultEventListener {
    const bool SHOW_ENV = false;
    const bool SHOW_TEST_CASES = false;
    const bool SHOW_TEST_NAMES = false;
    const bool SHOW_SUCCESSES = false;
    const bool SHOW_INLINE_FAILURES = false;
}

namespace EventListenerUtils {
    void setDefaultEventListener();
}

#endif
