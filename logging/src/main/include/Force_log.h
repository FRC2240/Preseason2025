#include "frc/Timer.h" 
#include "iostream"
#include "string"
#include "atomic"

enum severity {
    info,
    debug,
    warning,
    error
};

class Logframe {
public:
std::string message;
units::second_t fpga_timestamp;
units::second_t matchtime;
std::string severity;
std::atomic_int message_num = 0;
};



void force_log(severity message_severity, std::string message){
    
    Logframe current_frame;
    current_frame.fpga_timestamp = frc::Timer::GetFPGATimestamp();
    current_frame.matchtime = frc::Timer::GetMatchTime();
    current_frame.message = message;
    current_frame.severity = message_severity;
    std::cout<< "[" + current_frame.fpga_timestamp + 

}

