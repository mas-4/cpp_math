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
