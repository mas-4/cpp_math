//
// Created by mas on 4/17/22.
//

#include <stdexcept>
#include "trig.h"

double trig::sin(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::cos(double x) {
    int div = (int) (x / PI);
    x = x - (div * PI);
    char sign = 1;
    if (div % 2 != 0)
        sign = -1;
    double result = 1.0;
    double inter = 1.0;
    double num = x * x;
    for (int i = 1; i <= N; i++) {
        double comp = 2.0 * i;
        double den = comp * (comp - 1.0);
        inter *= num / den;
        result += i % 2 == 0 ? inter : -inter;
    }
    return sign * result;
}

double trig::tan(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::asin(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::acos(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::atan(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::atan2(double y, double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::sinh(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::cosh(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::tanh(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::asinh(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::acosh(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}

double trig::atanh(double x)
{
    throw std::invalid_argument("sin() not implemented");
    return 0;
}
