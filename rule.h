#ifndef RULE_H
#define RULE_H

#include "cpuparameter.h"
#include "diskparameter.h"
#include "gpuparameter.h"
#include "powerparameter.h"
#include "temperatureparameter.h"
#include "fanparameter.h"

class Rule
{
public:
    Rule(CpuParameter cpu,
         DiskParameter disk,
         GpuParameter gpu,
         PowerParameter power,
         TemperatureParameter temperature,
         FanParameter fan);

    CpuParameter getCpu();
    DiskParameter getDisk();
    GpuParameter getGpu();
    PowerParameter getPower();
    TemperatureParameter getTemperature();
    FanParameter getFan();

private:
    CpuParameter cpu_;
    DiskParameter disk_;
    GpuParameter gpu_;
    PowerParameter power_;
    TemperatureParameter temperature_;
    FanParameter fan_;
};

#endif // RULE_H
