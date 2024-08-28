// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#pragma once
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <units/angle.h>
#include <units/length.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandPtr.h>


#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <frc2/command/RunCommand.h>
#include <frc2/command/Commands.h>
#include <frc2/command/CommandHelper.h>

class PinkArm : public frc2::SubsystemBase {
 public:
  PinkArm();

  frc2::CommandPtr SetAngle(units::degree_t angle);
  frc2::CommandPtr SetExtention(units::meter_t distance);
  units::degree_t GetAngle();
  units::meter_t GetExtention();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
ctre::phoenix6::hardware::TalonFX m_left_rotation {1};
ctre::phoenix6::hardware::TalonFX m_right_rotation {2};
ctre::phoenix6::hardware::TalonFX m_left_extention {3};
ctre::phoenix6::hardware::TalonFX m_right_extention {5};
ctre::phoenix6::hardware::CANcoder m_cancoder {4};
const double turns_to_distance = 0.022;
};
