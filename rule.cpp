#include "rule.h"

Rule::Rule(CpuParameter cpu,
           DiskParameter disk,
           GpuParameter gpu,
           PowerParameter power,
           TemperatureParameter temperature,
           FanParameter fan)
    : cpu_(cpu), disk_(disk), gpu_(gpu), power_(power), temperature_(temperature), fan_(fan)
{

}

CpuParameter Rule::getCpu()
{
    return cpu_;
}

DiskParameter Rule::getDisk()
{
    return disk_;
}

GpuParameter Rule::getGpu()
{
    return gpu_;
}

PowerParameter Rule::getPower()
{
    return power_;
}

TemperatureParameter Rule::getTemperature()
{
    return temperature_;
}

FanParameter Rule::getFan()
{
    return fan_;
}
