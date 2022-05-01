#ifndef CPUPARAMETER_H
#define CPUPARAMETER_H

#include <QtGlobal>

class CpuParameter
{
public:
    CpuParameter(qint8 load);

    bool isLow();
    bool isMiddle();
    bool isHigh();

private:
    qint8 load_;
};

#endif // CPUPARAMETER_H
