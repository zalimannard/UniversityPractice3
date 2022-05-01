#ifndef GPUPARAMETER_H
#define GPUPARAMETER_H

#include <QtGlobal>

class GpuParameter
{
public:
    GpuParameter(qint8 load);

    bool isLow();
    bool isMiddle();
    bool isHigh();

private:
    qint8 load_;
};

#endif // GPUPARAMETER_H
