#ifndef FANPARAMETER_H
#define FANPARAMETER_H

#include <QtGlobal>

#include "cpuparameter.h"
#include "diskparameter.h"
#include "gpuparameter.h"
#include "powerparameter.h"
#include "temperatureparameter.h"

class FanParameter
{
public:
    FanParameter(CpuParameter cpu,
                 DiskParameter disk,
                 GpuParameter gpu,
                 PowerParameter power,
                 TemperatureParameter temperature);

    bool isIdle();
    bool isLow();
    bool isNormal();
    bool isMiddle();
    bool isHigh();

private:
    qint8 load_;
};

#endif // FANPARAMETER_H
