#include "fuzziparameter.h"

qreal FuzziParameter::left (qreal a, qreal b, qreal x)
{
    if (x <= a)
    {
        return 1;
    }
    else if (x >= b)
    {
        return 0;
    }
    else
    {
        return ((b - x) / (b - a));
    }
}

qreal FuzziParameter::between (qreal a, qreal b, qreal c, qreal d, qreal x)
{
    if ((a <= x) && (x <= b))
    {
        return 1 - (b - x) / (b - a);
    }
    else if ((b <= x) && (x <= c))
    {
        return 1;
    }
    else if ((c <= x) && (x <= d))
    {
        return 1 - (x - c) / (d - c);
    }
    else
    {
        return 0;
    }
}

qreal FuzziParameter::right (qreal a, qreal b, qreal x)
{
    if (x <= a)
    {
        return 0;
    }
    else if (x >= b)
    {
        return 1;
    }
    else
    {
        return ((x - a) / (b - a));
    }
}

FuzziParameter::FuzziParameter()
{

}
