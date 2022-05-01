#include "gpuparameter.h"

GpuParameter::GpuParameter(qint8 load)
{
    load_ = load;
}

bool GpuParameter::isLow()
{
    return load_ < 20;
}

bool GpuParameter::isMiddle()
{
    return (load_ < 60) && (load_ >= 20);
}

bool GpuParameter::isHigh()
{
    return load_ >= 60;
}
