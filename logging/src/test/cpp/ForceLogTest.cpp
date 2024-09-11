#include <gtest/gtest.h>
#include "ForceLog.h"

class ForceLogTest : public testing::Test {
    protected:
        
};

TEST_F(ForceLogTest, EmptyInfoTest) {
    // TODO: Get time or strip time from parse
    EXPECT_EQ("[0:0] INFO: ", ForceLog::parse(ForceLog::Info, "", 0_s));
}