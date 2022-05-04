#ifndef CPUPARAMETER_H
#define CPUPARAMETER_H

#include <QtGlobal>

#include "fuzziparameter.h"

class CpuParameter : FuzziParameter
{
public:
    CpuParameter(qint8 load);

    qreal fuzziLow();
    qreal fuzziMiddle();
    qreal fuzziHigh();

private:
    qint8 load_;
};

#endif // CPUPARAMETER_H
