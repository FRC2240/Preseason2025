Force log

for each of the following severities include:
fpga timestamp via driver station
severity should be a enum
differing color ansi for severities
driver station data manager

`ForceLog::Info(string)` to create an info level log given a string

`ForceLog::Debug(string)` That but debug level

`ForceLog::Warn(string)` A warning level 

`ForceLog::Error(string)` An error level


log frame class should have
message 
severity
timestamp