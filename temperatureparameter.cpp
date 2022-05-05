#include "temperatureparameter.h"

TemperatureParameter::TemperatureParameter(qint16 temperature)
{
    temperature_ = temperature;
}

qreal TemperatureParameter::fuzziLow()
{
    return left(15, 45, temperature_);
}

qreal TemperatureParameter::fuzziMiddle()
{
    return between(15, 45, 50, 80, temperature_);
}

qreal TemperatureParameter::fuzziHigh()
{
    return right(50, 80, temperature_);
}
