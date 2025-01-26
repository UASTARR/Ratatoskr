#include <gtest/gtest.h>
#include "./core.hpp"

TEST(HelloTest, BasicAssertions) {
    Example *ex = new Example();

    EXPECT_EQ(ex->returnNumber(), 1);

    delete ex;
}
