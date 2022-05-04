#ifndef TEMPERATUREPARAMETER_H
#define TEMPERATUREPARAMETER_H

#include <QtGlobal>

#include "fuzziparameter.h"

class TemperatureParameter : FuzziParameter
{
public:
    TemperatureParameter(qint16 temperature);

    qreal fuzziLow();
    qreal fuzziMiddle();
    qreal fuzziHigh();

private:
    qint16 temperature_;
};

#endif // TEMPERATUREPARAMETER_H
