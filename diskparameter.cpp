#include "diskparameter.h"

DiskParameter::DiskParameter(qint8 load)
{
    load_ = load;
}

bool DiskParameter::isNormal()
{
    return load_ < 50;
}

bool DiskParameter::isHigh()
{
    return load_ >= 50;
}
