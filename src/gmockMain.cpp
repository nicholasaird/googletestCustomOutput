#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "EventListenerUtils.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);

    EventListenerUtils::setDefaultEventListener();

    return RUN_ALL_TESTS();
}
