#include "MotorLog.h"
#include "magic_enum.hpp"

/*
MotorLog::ReadableStatusCode MotorLog::ParseStatusCode(ctre::phoenix::StatusCode code) {
    std::string error = magic_enum::enum_name(code.Get);
    enum MotorLog::severityLevel level;

    switch(code) {
        case ctre::phoenix::StatusCode::OK:
            level = OK;
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
            level = ERROR;
            break;
        case ctre::phoenix::StatusCode::GeneralWarning:
        case ctre::phoenix::StatusCode::ControlModeNotValid:
        case ctre::phoenix::StatusCode::GainsAreNotSet:
        case ctre::phoenix::StatusCode::WrongRemoteLimitSwitchSource:
        case ctre::phoenix::StatusCode::DoubleVoltageCompensatingWPI:
        case ctre::phoenix::StatusCode::IncompatibleMode:
            level = WARNING;
            break;
        default:
            level = NOTAPPLICABLE;
    }
}
*/

void MotorLog::test() {
    ctre::phoenix6::configs::TalonFXConfiguration test_config{};
    testMotor.GetConfigurator().Apply(test_config);
    ctre::phoenix::StatusCode code = testMotor.SetControl(ctre::phoenix6::controls::VoltageOut{units::volt_t{1.0}});
    std::cout << code.GetName();

}