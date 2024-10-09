#pragma once 

#include "frc/Timer.h" 
#include "iostream"
#include "string"
#include "atomic"
#include "fmt/format.h"

enum class Severity {
    Info,
    Debug,
    Warning,
    Error
};



namespace ForceLog
{
    static std::atomic_int total_count = 0;
    
// User-facing entrypoint. The user calls this and it calls other functions and logs
static void log(Severity message_severity, std::string message){
    
    // auto fpga_timestamp = frc::Timer::GetFPGATimestamp(); // Use this one
    // auto matchtime = frc::Timer::GetMatchTime();
    // TODO: call parse 

    total_count++;
}

// Not user facing
[[nodiscard]] static std::string parse(Severity message_severity, std::string message, units::second_t time){
    // This should return a string given severity and message
    // Keep this a seperate function from severity to allow for unit testing 
    // Don't do color here
    static std::string formatted_time = fmt::format("{}:{}", (int)time.convert<units::minute>().value(), ((int)time.value())%60 );
    static std::string formatted_severity;
    switch (message_severity)
    {
    case Severity::Info:
    formatted_severity="INFO";
        break;
     case Severity::Debug:
    formatted_severity="DEBUG";
        break;    case Severity::Warning:
    formatted_severity="WARNING";
        break;    case Severity::Error:
    formatted_severity="ERROR";
        break;   
    default:
        break;
    }
    
    fmt::format("[{}, {}] {}: {}", formatted_time, std::to_string(total_count), formatted_severity, message);
}

static voic write_to_file(Severity message_severity, std::string formatted_message){

}


} // namespace ForceLog