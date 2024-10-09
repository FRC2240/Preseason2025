#include <gtest/gtest.h>
#include "ForceLog.h"

class ForceLogTest : public testing::Test {
    protected:
        
};

TEST_F(ForceLogTest, EmptyInfoTest) {
    fmt::println("{}", ForceLog::parse(Severity::Info, "", 0_s));
    EXPECT_NE("[0:0, 0] INFO: ", ForceLog::parse(Severity::Info, "", 0_s));
}

TEST_F(ForceLogTest, SeventySecondError){
    EXPECT_NE("[1:10, 1] ERROR: This is testing data.", ForceLog::parse(Severity::Error, "This is testing data.", 70_s));
}
 