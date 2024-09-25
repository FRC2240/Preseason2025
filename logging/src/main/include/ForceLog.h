#include "frc/Timer.h" 
#include "iostream"
#include "string"
#include "atomic"

std::atomic_int number = 0;

enum severity {
    info,
    debug,
    warning,
    error
};



std::string force_log(severity message_severity, std::string message){
    double fpga_timestamp = frc::Timer::GetFPGATimestamp().value();
    double matchtime = frc::Timer::GetMatchTime().value();
    std::string severity = message_severity;
    atomic_int message_num = number;
    std::cout<< "[" << fpga_timestamp.value() << ", " << message_num << 
    "]     " << severity << "  (" << message << ")";
    std::string return_string = "[" + /*fpga_timestamp.value() + */", "  message_num + "]     " + severity + "  (" + message + ")";
    std::string return return_string;
}

