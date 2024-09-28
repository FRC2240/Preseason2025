// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>


RobotContainer::RobotContainer() {
  TestCandle();
}

void RobotContainer::TestCandle(){
    ctre::phoenix::led::CANdleConfiguration config;
    config.stripType = ctre::phoenix::led::LEDStripType::RGB; // GRB?
    config.brightnessScalar = 0.5;
    m_candle.ConfigAllSettings(config);
    m_candle.ClearAnimation(0);
    m_candle.SetLEDs(0, 0, 0);
    timer.Start();

}

void RobotContainer::TestCandlePeriodic() {
  if (timer.Get() > units::second_t{10}) {
    timer.Restart();
    counter++;
    flag = true;
  }   
  
  if (flag) {
    flag = false;
    switch (counter) {
      case 0:
        m_candle.SetLEDs(0,255,0);
        break;
      case 1:
        m_candle.Animate(test_rainbow);
        break;
      case 2:
        m_candle.Animate(test_strobe);
        break;
      case 3:
        m_candle.Animate(test_larson);
        break;
      case 4:
        m_candle.Animate(test_fire);
        break;
      case 5:
        m_candle.Animate(test_fade);
        break;
      case 6:
        m_candle.Animate(test_flow);
        break;
      case 7:
        m_candle.Animate(test_single);
        break;
      case 8:
        m_candle.Animate(test_twinkle);
        break;

    }
  }

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
