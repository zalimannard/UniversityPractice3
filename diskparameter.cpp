#include "diskparameter.h"

DiskParameter::DiskParameter(qint8 load)
{
    load_ = load;
}

qreal DiskParameter::fuzziLow()
{
    return left(45, 55, load_);
}

qreal DiskParameter::fuzziHigh()
{
    return right(45, 55, load_);
}
