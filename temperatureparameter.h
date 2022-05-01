#ifndef TEMPERATUREPARAMETER_H
#define TEMPERATUREPARAMETER_H

#include <QtGlobal>

class TemperatureParameter
{
public:
    TemperatureParameter(qint16 temperature);

    bool isLow();
    bool isNormal();
    bool isHigh();
    bool isVeryHigh();

private:
    qint16 temperature_;
};

#endif // TEMPERATUREPARAMETER_H
