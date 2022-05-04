#include "gpuparameter.h"

GpuParameter::GpuParameter(qint8 load)
{
    load_ = load;
}

qreal GpuParameter::fuzziLow()
{
    return left(20, 30, load_);
}

qreal GpuParameter::fuzziMiddle()
{
    return between(20, 30, 60, 70, load_);
}

qreal GpuParameter::fuzziHigh()
{
    return right(60, 70, load_);
}
