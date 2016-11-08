#include "gtest/gtest.h"

#include "EventListenerUtils.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    EventListenerUtils::setDefaultEventListener();

    return RUN_ALL_TESTS();
}
