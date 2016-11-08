#include "gtest/gtest.h"

#include "EventListenerUtils.h"

void setTestEventListener();

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    EventListenerUtils::setTestEventListener();

    return RUN_ALL_TESTS();
}
