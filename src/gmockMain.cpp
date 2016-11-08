#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "EventListenerUtils.h"

void setTestEventListener();

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);

    EventListenerUtils::setTestEventListener();

    return RUN_ALL_TESTS();
}
