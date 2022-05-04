#include "fanparameter.h"

FanParameter::FanParameter(qint8 load)
{
    load_ = load;
}

qreal FanParameter::fuzziIdle()
{
    return load_ < 20;
}

qreal FanParameter::fuzziLow()
{
    return (load_ < 40) && (load_ >= 20);
}

qreal FanParameter::fuzziNormal()
{
    return (load_ < 60) && (load_ >= 40);
}

qreal FanParameter::fuzziHigh()
{
    return load_ >= 80;
}
