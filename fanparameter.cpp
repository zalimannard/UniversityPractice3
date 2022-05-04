#include "fanparameter.h"

FanParameter::FanParameter(qint8 load)
{
    load_ = load;
}

qreal FanParameter::fuzziIdle()
{
    return 20;
}

qreal FanParameter::fuzziLow()
{
    return 40;
}

qreal FanParameter::fuzziNormal()
{
    return 60;
}

qreal FanParameter::fuzziMiddle()
{
    return 80;
}

qreal FanParameter::fuzziHigh()
{
    return 100;
}
