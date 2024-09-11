#include "frc/Timer.h" 
#include "iostream"
#include "string"
#include "atomic"
#include "fmt/format.h"

enum class severity {
    Info,
    Debug,
    Warning,
    Error
};


[[depreciated]] class Logframe {
public:
std::string message;
units::second_t fpga_timestamp;
units::second_t matchtime;
std::string severity;
std::atomic_int message_num = 0;
};


namespace ForceLog
{
    static std::atomic_int total_count = 0;
    
// User-facing entrypoint. The user calls this and it calls other functions and logs
void log(severity message_severity, std::string message){
    
    Logframe current_frame;
    current_frame.fpga_timestamp = frc::Timer::GetFPGATimestamp(); // Use this one
    current_frame.matchtime = frc::Timer::GetMatchTime();
    current_frame.message = message;
    current_frame.severity = message_severity; // This won't compile as Enums *cannot* be casted to strings
    // TODO: call parse 

    total_count++;
}

// Not user facing
[[nodiscard]] std::string parse(severity message_severity, std::string message, units::second_t time){
    // This should return a string given severity and message
    // Keep this a seperate function from severity to allow for unit testing 
}


} // namespace ForceLog