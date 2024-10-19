// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include "ctre/phoenix/led/CANdle.h"
#include "ctre/phoenix/led/RainbowAnimation.h"
#include "ctre/phoenix/led/StrobeAnimation.h"
#include "ctre/phoenix/led/LarsonAnimation.h"
#include "ctre/phoenix/led/FireAnimation.h"
#include "ctre/phoenix/led/RgbFadeAnimation.h"
#include "ctre/phoenix/led/ColorFlowAnimation.h"
#include "ctre/phoenix/led/SingleFadeAnimation.h"
#include "ctre/phoenix/led/TwinkleAnimation.h"
#include <frc/Timer.h>
#include <iostream>

constexpr int CANDLE_ID = 10; //CHANGEME
constexpr int NUM_LEDS = -1; //CHANGEME


class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();
  void TestCandle();
  void TestCandlePeriodic();
 private:
  ctre::phoenix::led::CANdle m_candle{CANDLE_ID};
  frc::Timer timer {};
  int counter = 0;
  bool flag = true;

    //                                                 brt  spd
    ctre::phoenix::led::RainbowAnimation test_rainbow {0.5, 0.5};
    
    //                                               r    g    b    w  spd
    ctre::phoenix::led::StrobeAnimation test_strobe {255, 234, 0,   0, 0.5};

    //                                               r    g  b  w  spd  num
    ctre::phoenix::led::LarsonAnimation test_larson {255, 0, 0, 0, 0.5, NUM_LEDS};

    //                                           brg  spd  num       sprk cool rev    offset
    ctre::phoenix::led::FireAnimation test_fire {0.5, 0.5, NUM_LEDS, 0.5, 0.5, false, 0     };

    //                                              brg  spd  num       offset
    ctre::phoenix::led::RgbFadeAnimation test_fade {0.5, 0.5, NUM_LEDS, 0     };

    //                                                r    g  b    w  spd  num
    ctre::phoenix::led::ColorFlowAnimation test_flow {255, 0, 255, 0, 0.5, NUM_LEDS};

    //                                                   r    g  b    w  spd  num       offset
    ctre::phoenix::led::SingleFadeAnimation test_single {255, 0, 127, 0, 0.5, NUM_LEDS, 0     };

    //                                                 r    g  b    w  spd  num
    ctre::phoenix::led::TwinkleAnimation test_twinkle {255, 0, 127, 0, 0.5, NUM_LEDS};



};
