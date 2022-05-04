#ifndef FANPARAMETER_H
#define FANPARAMETER_H

#include <QtGlobal>

#include "fuzziparameter.h"

class FanParameter : FuzziParameter
{
public:
    FanParameter(qint8 load);

    qreal fuzziIdle();
    qreal fuzziLow();
    qreal fuzziNormal();
    qreal fuzziMiddle();
    qreal fuzziHigh();

private:
    qint8 load_;
};

#endif // FANPARAMETER_H
