#include "diskparameter.h"

DiskParameter::DiskParameter(qint8 load)
{
    load_ = load;
}

qreal DiskParameter::fuzziLow()
{
    return left(25, 75, load_);
}

qreal DiskParameter::fuzziHigh()
{
    return right(25, 75, load_);
}
