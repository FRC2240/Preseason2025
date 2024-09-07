#include <gtest/gtest.h>

class testTest : public testing::Test {
    protected:
        int a = 1;
};

TEST_F(testTest, OneEqualsOne) {
  ASSERT_EQ(1,1);
}