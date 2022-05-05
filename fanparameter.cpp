#include "fanparameter.h"

FanParameter::FanParameter()
{

}

qreal FanParameter::fuzziIdle()
{
    return 0;
}

qreal FanParameter::fuzziLow()
{
    return 20;
}

qreal FanParameter::fuzziNormal()
{
    return 40;
}

qreal FanParameter::fuzziMiddle()
{
    return 60;
}

qreal FanParameter::fuzziHigh()
{
    return 80;
}

qreal FanParameter::fuzziVeryHigh()
{
    return 100;
}
