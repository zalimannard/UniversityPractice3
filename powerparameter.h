#ifndef POWERPARAMETER_H
#define POWERPARAMETER_H

class PowerParameter
{
public:
    PowerParameter(bool enabled);

    bool isEnabled();
    bool isDisabled();

private:
    bool enabled_;
};

#endif // POWERPARAMETER_H
