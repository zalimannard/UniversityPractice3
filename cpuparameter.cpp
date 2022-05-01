#include "cpuparameter.h"

CpuParameter::CpuParameter(qint8 load)
{
    load_ = load;
}

bool CpuParameter::isLow()
{
    return load_ < 30;
}

bool CpuParameter::isMiddle()
{
    return (load_ < 70) && (load_ >= 30);
}

bool CpuParameter::isHigh()
{
    return load_ >= 70;
}
