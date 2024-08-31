#include "MotorLog.h"
#include "magic_enum.hpp"


MotorLog::ReadableStatusCode MotorLog::ParseStatusCode(ctre::phoenix::StatusCode code) {
    
    //enum MotorLog::severityLevel level;
    MotorLog::ReadableStatusCode ReadableCode;
    ReadableCode.name = code.GetName();
    ReadableCode.description = code.GetDescription();

    switch(code) {
        case ctre::phoenix::StatusCode::OK:
            ReadableCode.severity = OK;
            break;
        case ctre::phoenix::StatusCode::EcuIsNotPresent:
        case ctre::phoenix::StatusCode::NoDevicesOnBus:
        case ctre::phoenix::StatusCode::NodeIsInvalid:
        case ctre::phoenix::StatusCode::FeatureNotSupported:
        case ctre::phoenix::StatusCode::ConfigFailed:
        case ctre::phoenix::StatusCode::InvalidModel:
        case ctre::phoenix::StatusCode::DeviceIsNull:
        case ctre::phoenix::StatusCode::RxTimeout:
        case ctre::phoenix::StatusCode::SensorNotPresent:
        case ctre::phoenix::StatusCode::GeneralError:
        case ctre::phoenix::StatusCode::MechanismFaulted:
            ReadableCode.severity = ERROR;
            break;
        case ctre::phoenix::StatusCode::GeneralWarning:
        case ctre::phoenix::StatusCode::ControlModeNotValid:
        case ctre::phoenix::StatusCode::GainsAreNotSet:
        case ctre::phoenix::StatusCode::WrongRemoteLimitSwitchSource:
        case ctre::phoenix::StatusCode::DoubleVoltageCompensatingWPI:
        case ctre::phoenix::StatusCode::IncompatibleMode:
            ReadableCode.severity = WARNING;
            break;
        default:
            ReadableCode.severity = NOTAPPLICABLE;
    }

    return ReadableCode;
}