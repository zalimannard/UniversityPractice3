#include "cpuparameter.h"

CpuParameter::CpuParameter(qint8 load)
{
    load_ = load;
}

qreal CpuParameter::fuzziLow()
{
    return left(30, 40, load_);
}

qreal CpuParameter::fuzziMiddle()
{
    return between(30, 40, 60, 70, load_);
}

qreal CpuParameter::fuzziHigh()
{
    return right(60, 70, load_);
}
