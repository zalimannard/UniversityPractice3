#ifndef RULE_H
#define RULE_H

#include "cpuparameter.h"
#include "diskparameter.h"
#include "gpuparameter.h"
#include "powerparameter.h"
#include "temperatureparameter.h"
#include "fanparameter.h"

#include <QString>

class Rule
{
public:
    Rule(QString cpu,
         QString disk,
         QString gpu,
         QString power,
         QString temperature,
         qreal fan);

    qreal fuzziCompareCpu(qreal value);
    qreal fuzziCompareDisk(qreal value);
    qreal fuzziCompareGpu(qreal value);
    qreal fuzziComparePower(qreal value);
    qreal fuzziCompareTemperature(qreal value);

    QString getCpu();
    QString getDisk();
    QString getGpu();
    QString getPower();
    QString getTemperature();
    qreal getFan();

private:
    QString cpu_;
    QString disk_;
    QString gpu_;
    QString power_;
    QString temperature_;
    qreal fan_;
};

#endif // RULE_H
