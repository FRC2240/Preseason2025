#pragma once

#include "frc/Timer.h"
#include "iostream"
#include "string"
#include "atomic"
#include "fmt/format.h"
// Shuffuleboard API is compatable with Elastic. Use Elastic, not shuffleboard
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DataLogManager.h>
#include <frc/Timer.h>
#include <Elastic.h>
#include <fmt/color.h>

namespace ForceLog
{
    static void info(std::string title, std::string message = "")
    {
        elastic::SendAlert(elastic::Notification{elastic::Notification::Level::INFO, title, message});
        frc::DataLogManager::Log("[info] " + '(' + std::to_string(frc::Timer::GetFPGATimestamp().value()) + ") " + title + ": " + message + "\n");
    }

    static void warn(std::string title, std::string message = "")
    {
        elastic::SendAlert(elastic::Notification{elastic::Notification::Level::WARNING, title, message});
        frc::DataLogManager::Log(fmt::format(fmt::emphasis::bold | fg(fmt::color::yellow),
                                             "[warning] " + '(' + std::to_string(frc::Timer::GetFPGATimestamp().value()) + ") " + title + ": " + message + "\n"));
    }

    static void error(std::string title, std::string message = "")
    {
        elastic::SendAlert(elastic::Notification{elastic::Notification::Level::ERROR, title, message});
        frc::DataLogManager::Log(fmt::format(fmt::emphasis::bold | bg(fmt::color::yellow),
                                             "[error] " + '(' + std::to_string(frc::Timer::GetFPGATimestamp().value()) + ") " + title + ": " + message + "\n"));
    }

} // namespace ForceLog