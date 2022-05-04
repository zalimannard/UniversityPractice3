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
    Rule(QString cpu,
         QString disk,
         QString gpu,
         QString power,
         QString temperature,
         qreal fan);

private:
    CpuParameter cpu_;
    DiskParameter disk_;
    GpuParameter gpu_;
    PowerParameter power_;
    TemperatureParameter temperature_;
    FanParameter fan_;
};

#endif // RULE_H
