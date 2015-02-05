#include <iostream>
#include "Version.h"

#include "gtest/gtest.h"

using namespace libcellml;

//! IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(Version, Version) {
    auto v1 = getVersion();
    auto v2 = getVersion();
    EXPECT_EQ(v1, v2);
}


