#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "TestListenerUtils.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);

    TestListenerUtils::Listener* listener = TestListenerUtils::createEventListener();
    TestListenerUtils::setEventListener(listener);

    return RUN_ALL_TESTS();
}
