// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/PinkArm.h"

PinkArm::PinkArm(){
    ctre::phoenix6::configs::TalonFXConfiguration left_conf{};
    left_conf.Feedback.WithRemoteCANcoder(m_cancoder);

    ctre::phoenix6::configs::TalonFXConfiguration right_conf{};
    right_conf.MotorOutput.Inverted = ctre::phoenix6::signals::InvertedValue::Clockwise_Positive;
}

// This method will be called once per scheduler run
void PinkArm::Periodic() {}

frc2::CommandPtr PinkArm::SetExtention(units::meter_t distance)
{
    return frc2::cmd::Run([this, distance]{
        ctre::phoenix6::controls::PositionVoltage req {distance};
        req.EnableFOC = 1;

        this->m_left_extention.SetControl(req);
    },{this} ).Until();
}

units::degree_t PinkArm::GetAngle()
{
    return units::degree_t();
}

units::meter_t PinkArm::GetExtention()
{
    return units::meter_t();
}

{
    return units::meter_t{m_left_extention.GetPosition().GetValueAsDouble()*turns_to_distance};
}

