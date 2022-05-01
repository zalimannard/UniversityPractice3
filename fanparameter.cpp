#include "fanparameter.h"

FanParameter::FanParameter(CpuParameter cpu,
                           DiskParameter disk,
                           GpuParameter gpu,
                           PowerParameter power,
                           TemperatureParameter temperature)
{
    load_ = 0;
}

bool FanParameter::isIdle()
{
    return load_ < 20;
}

bool FanParameter::isLow()
{
    return (load_ < 40) && (load_ >= 20);
}

bool FanParameter::isNormal()
{
    return (load_ < 60) && (load_ >= 40);
}

bool FanParameter::isMiddle()
{
    return (load_ < 80) && (load_ >= 60);
}

bool FanParameter::isHigh()
{
    return load_ >= 80;
}
