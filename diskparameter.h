#ifndef DISKPARAMETER_H
#define DISKPARAMETER_H

#include <QtGlobal>

class DiskParameter
{
public:
    DiskParameter(qint8 load);

    bool isNormal();
    bool isHigh();

private:
    qint8 load_;
};

#endif // DISKPARAMETER_H
