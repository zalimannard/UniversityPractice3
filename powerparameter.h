#ifndef POWERPARAMETER_H
#define POWERPARAMETER_H

#include <QtGlobal>

#include "fuzziparameter.h"

class PowerParameter : FuzziParameter
{
public:
    PowerParameter(bool enabled);

    qreal fuzziEnabled();
    qreal fuzziDisabled();

private:
    bool enabled_;
};

#endif // POWERPARAMETER_H
