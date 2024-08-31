#pragma once

#include <ctre/phoenix/StatusCodes.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <units/voltage.h>
#include <iostream>

namespace MotorLog {

    enum severityLevel {
        ERROR,
        WARNING,
        OK,
        NOTAPPLICABLE
    };

    struct ReadableStatusCode {
        std::string status;
        enum severityLevel severity;
        ctre::phoenix::StatusCode originalCode;
    };

    ctre::phoenix6::hardware::TalonFX testMotor{0};
    void test(); 
        
    //MotorLog::ReadableStatusCode ParseStatusCode(ctre::phoenix::StatusCode code);

}