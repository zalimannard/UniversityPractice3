#include "cpuparameter.h"

CpuParameter::CpuParameter(qint8 load)
{
    load_ = load;
}

qreal CpuParameter::fuzziLow()
{
    return left(10, 40, load_);
}

qreal CpuParameter::fuzziMiddle()
{
    return between(10, 40, 50, 90, load_);
}

qreal CpuParameter::fuzziHigh()
{
    return right(50, 90, load_);
}
