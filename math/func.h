//
// Created by mas on 4/17/22.
//

#ifndef MS_MATH_FUNC_H
#define MS_MATH_FUNC_H

struct fraction {
    int num;
    int den;
};

namespace func
{
    double abs(double x);

    double sqrt(double x);

    double Q_rsqrt(double x);

    double Q_sqrt(double x);

    fraction decompose(double x);

    long pow(long x, long y);

    double pow(double x, double y);

    double exp(double x);

    double ln(double x);

    double log(double x);
}

#endif //MS_MATH_FUNC_H
