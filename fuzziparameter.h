#ifndef FUZZIPARAMETER_H
#define FUZZIPARAMETER_H

#include <QtGlobal>

class FuzziParameter
{
public:
    qreal left (qreal a, qreal b, qreal x);
    qreal between (qreal a, qreal b, qreal c, qreal d, qreal x);
    qreal right (qreal a, qreal b, qreal x);

protected:
    FuzziParameter();
};

#endif // FUZZIPARAMETER_H
