#include "temperatureparameter.h"

TemperatureParameter::TemperatureParameter(qint16 temperature)
{
    temperature_ = temperature;
}

qreal TemperatureParameter::fuzziLow()
{
    return left(15, 25, temperature_);
}

qreal TemperatureParameter::fuzziMiddle()
{
    return between(15, 25, 50, 60, temperature_);
}

qreal TemperatureParameter::fuzziHigh()
{
    return right(50, 60, temperature_);
}
