#include "rule.h"

Rule::Rule(QString cpu,
           QString disk,
           QString gpu,
           QString power,
           QString temperature,
           qreal fan)
{
    cpu_ = cpu;
    disk_ = disk;
    gpu_ = gpu;
    power_ = power;
    temperature_ = temperature;
    fan_ = fan;
}

qreal Rule::fuzziCompareCpu(qreal value)
{
    if (getCpu() == "low")
    {
        return CpuParameter(value).fuzziLow();
    }
    else if (getCpu() == "middle")
    {
        return CpuParameter(value).fuzziMiddle();
    }
    else if (getCpu() == "high")
    {
        return CpuParameter(value).fuzziHigh();
    }
    return 999999;
}

qreal Rule::fuzziCompareDisk(qreal value)
{
    if (getDisk() == "low")
    {
        return DiskParameter(value).fuzziLow();
    }
    else if (getDisk() == "high")
    {
        return DiskParameter(value).fuzziHigh();
    }
    return 0;
}

qreal Rule::fuzziCompareGpu(qreal value)
{
    if (getGpu() == "low")
    {
        return GpuParameter(value).fuzziLow();
    }
    else if (getGpu() == "middle")
    {
        return GpuParameter(value).fuzziMiddle();
    }
    else if (getGpu() == "high")
    {
        return GpuParameter(value).fuzziHigh();
    }
    return 0;
}

qreal Rule::fuzziComparePower(bool value)
{
    if (getPower() == "enable")
    {
        return PowerParameter(value).fuzziEnabled();
    }
    else if (getPower() == "disable")
    {
        return PowerParameter(value).fuzziDisabled();
    }
    return 0;
}

qreal Rule::fuzziCompareTemperature(qreal value)
{
    if (getTemperature() == "low")
    {
        return TemperatureParameter(value).fuzziLow();
    }
    else if (getTemperature() == "middle")
    {
        return TemperatureParameter(value).fuzziMiddle();
    }
    else if (getCpu() == "high")
    {
        return TemperatureParameter(value).fuzziHigh();
    }
    return 0;
}

QString Rule::getCpu()
{
    return cpu_;
}

QString Rule::getDisk()
{
    return disk_;
}

QString Rule::getGpu()
{
    return gpu_;
}

QString Rule::getPower()
{
    return power_;
}

QString Rule::getTemperature()
{
    return temperature_;
}

qreal Rule::getFan()
{
    return fan_;
}
