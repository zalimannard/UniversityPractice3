#include "temperatureparameter.h"

TemperatureParameter::TemperatureParameter(qint16 temperature)
{
    temperature_ = temperature;
}

bool TemperatureParameter::isLow()
{
    return temperature_ < 10;
}

bool TemperatureParameter::isNormal()
{
    return (temperature_ < 50) && (temperature_ >= 10);
}

bool TemperatureParameter::isHigh()
{
    return (temperature_ < 90) && (temperature_ >= 50);
}

bool TemperatureParameter::isVeryHigh()
{
    return temperature_ >= 90;
}
