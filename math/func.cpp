//
// Created by mas on 4/17/22.
//

#include <stdexcept>
#include "func.h"

double func::abs(double x)
{
    return x > 0 ? x : -x;
}

double func::sqrt(double x)
{
    throw std::invalid_argument("Not implemented");
    return 0;
}

double func::Q_rsqrt(double number)
{
    // Regurgitated by Copilot, changed to doubles because why not

    long i;
    double x2, y;
    const double threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( double * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

double func::Q_sqrt(double number)
{
    // Hey, Copilot figured out how to do a reciprocal.
    return 1.0 / Q_rsqrt(number);
}

double func::pow(double x, double y)
{
    throw std::invalid_argument("Not implemented");
    return 0;
}

double func::exp(double x)
{
    throw std::invalid_argument("Not implemented");
    return 0;
}

double func::ln(double x)
{
    throw std::invalid_argument("Not implemented");
    return 0;
}

double func::log(double x)
{
    throw std::invalid_argument("Not implemented");
    return 0;
}
