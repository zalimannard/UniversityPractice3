#include "powerparameter.h"

PowerParameter::PowerParameter(bool enabled)
{
    enabled_ = enabled;
}

bool PowerParameter::isEnabled()
{
    return enabled_;
}

bool PowerParameter::isDisabled()
{
    return !enabled_;
}
