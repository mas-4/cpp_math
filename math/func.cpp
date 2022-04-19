//
// Created by mas on 4/17/22.
//

#include <stdexcept>
#include <limits>
#include "func.h"

double func::abs(double x)
{
    return x > 0 ? x : -x;
}

double func::sqrt(double x)
{
    if (x < 0)
        throw std::invalid_argument("sqrt: negative argument");
    if (x == 0)
        return 0;
    double xn = x;
    double eps = 1e-15;
    double last = xn;
    while ((xn * xn - x) > eps) {
        last = xn;
        xn = (xn + (x / xn)) / 2;
        if (xn == last) // sometimes convergence is not reached
            break;
    }
    return xn;
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
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

double func::Q_sqrt(double number)
{
    // Hey, Copilot figured out how to do a reciprocal.
    double q_rsqrt = func::Q_rsqrt(number);
    if (q_rsqrt == 0)
        return 0;
    return 1.0 / q_rsqrt;
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

fraction func::decompose(double x)
{
    throw std::invalid_argument("Not implemented");
    return fraction();
}

long func::pow(long x, long y)
{
    long x2 = x;
    for (long i = 1; i < y; i++)
    {
        x2 *= x;
    }
    return x2;
}

double func::polynomial(double x, const double *coeffs, int n)
{
    double y = 0;
    double x2 = 1;
    for (int i = 0; i < n; i++)
    {
        y += coeffs[i] * x2;
        x2 *= x;
    }
    return y;
}
