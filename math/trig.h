//
// Created by mas on 4/17/22.
//

#ifndef MS_MATH_TRIG_H
#define MS_MATH_TRIG_H

#define modd(x, y) ((x) - (int)((x) / (y)) * (y))
#define PI 3.14159265358979323846
#define PI_2 2 * PI
#define N 10

namespace trig {
    double sin(double x);
    double cos(double x);
    double tan(double x);
    double asin(double x);
    double acos(double x);
    double atan(double x);
    double atan2(double y, double x);
    double sinh(double x);
    double cosh(double x);
    double tanh(double x);
    double asinh(double x);
    double acosh(double x);
    double atanh(double x);
}


#endif //MS_MATH_TRIG_H
