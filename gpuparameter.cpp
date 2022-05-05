#include "gpuparameter.h"

GpuParameter::GpuParameter(qint8 load)
{
    load_ = load;
}

qreal GpuParameter::fuzziLow()
{
    return left(10, 40, load_);
}

qreal GpuParameter::fuzziMiddle()
{
    return between(10, 40, 50, 90, load_);
}

qreal GpuParameter::fuzziHigh()
{
    return right(50, 90, load_);
}
