#include "powerparameter.h"

PowerParameter::PowerParameter(bool enabled)
{
    enabled_ = enabled;
}

qreal PowerParameter::fuzziEnabled()
{
    if (enabled_)
    {
        return right(0.1, 0.9, 1);
    }
    else
    {
        return left(0.1, 0.9, 0);
    }
}

qreal PowerParameter::fuzziDisabled()
{
    if (enabled_)
    {
        return left(0.1, 0.9, 0);
    }
    else
    {
        return right(0.1, 0.9, 1);
    }
}
