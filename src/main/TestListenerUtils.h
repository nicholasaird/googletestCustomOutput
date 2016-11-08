#ifndef TESTLISTENERUTILS_HPP
#define TESTLISTENERUTILS_HPP

#include <memory>  // shared_ptr

#include "gtest/gtest.h"

#include "ConfigurableEventListener.h"

namespace TestListenerUtils {
    typedef testing::TestEventListener Listener;
    typedef testing::TestEventListeners Listeners;

    Listener* createEventListener();
    Listener* getCurrentListener();
    Listeners& getListeners();
    void setEventListener(Listener* listener);
}

#endif
