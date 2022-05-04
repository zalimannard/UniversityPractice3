#ifndef DISKPARAMETER_H
#define DISKPARAMETER_H

#include <QtGlobal>

#include "fuzziparameter.h"

class DiskParameter : FuzziParameter
{
public:
    DiskParameter(qint8 load);

    qreal fuzziLow();
    qreal fuzziHigh();

private:
    qint8 load_;
};

#endif // DISKPARAMETER_H
