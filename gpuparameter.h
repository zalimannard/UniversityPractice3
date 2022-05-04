#ifndef GPUPARAMETER_H
#define GPUPARAMETER_H

#include <QtGlobal>

#include "fuzziparameter.h"

class GpuParameter : FuzziParameter
{
public:
    GpuParameter(qint8 load);

    qreal fuzziLow();
    qreal fuzziMiddle();
    qreal fuzziHigh();

private:
    qint8 load_;
};

#endif // GPUPARAMETER_H
