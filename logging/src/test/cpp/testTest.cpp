#include <gtest/gtest.h>
#include "MotorLog.h"
#include <ctre/phoenix/StatusCodes.h>

class testTest : public testing::Test {
    protected:
        ctre::phoenix::StatusCode testCode = ctre::phoenix::StatusCode::NoDevicesOnBus;
        
};

TEST_F(testTest, StatusCodeSeverityError) {
    MotorLog::ReadableStatusCode newCode = MotorLog::ParseStatusCode(testCode);
    EXPECT_NE(newCode.severity, MotorLog::severityLevel::OK);
}