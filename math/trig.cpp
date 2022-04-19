//
// Created by mas on 4/17/22.
//

#include <stdexcept>
#include "trig.h"
#include "func.h"

double trig::sin(double x)
{
    double sin_x = trig::cos(PI_2 - x);
    return sin_x;
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
    // TODO use a first order algorithm instead of algebra
    double tan_x = trig::sin(x) / trig::cos(x);
    return tan_x;
}

double trig::asin(double x)
{
    double arg_den = func::sqrt(1.0 - x * x);
    double arg_num = x;
    double result = trig::atan(arg_num / arg_den);
    return result;
}

double trig::acos(double x)
{
    double acos_x = PI_2 - trig::asin(x);
    return acos_x;
}

double trig::atan(double x)
{
    // https://dsp.stackexchange.com/a/20482
    if (-1 > x && x > 1)
        throw std::invalid_argument("atan only defined for -1 <= x <= 1");
    double x2 = x * x;
    double ATAN_COEFFS[] {
        1.0,
        0.33288950512027,
        -0.08467922817644,
        0.03252232640125,
        -0.00749305860992
    };
    double poly_x = func::polynomial(x2, ATAN_COEFFS, 5);
    return x / poly_x;
}

double trig::atan2(double y, double x)
{
    throw std::invalid_argument("atan2() not implemented");
    return 0;
}

double trig::sinh(double x)
{
    throw std::invalid_argument("sinh() not implemented");
    return 0;
}

double trig::cosh(double x)
{
    throw std::invalid_argument("cosh() not implemented");
    return 0;
}

double trig::tanh(double x)
{
    throw std::invalid_argument("tanh() not implemented");
    return 0;
}

double trig::asinh(double x)
{
    throw std::invalid_argument("asinh() not implemented");
    return 0;
}

double trig::acosh(double x)
{
    throw std::invalid_argument("acosh() not implemented");
    return 0;
}

double trig::atanh(double x)
{
    throw std::invalid_argument("atanh() not implemented");
    return 0;
}
