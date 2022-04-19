//
// Created by mas on 4/17/22.
//

#include <valarray>
#include "func_tests.h"
#include "func.h"

bool test_abs()
{
    bool success = func::abs(-1) == 1;
    success &= func::abs(1) == 1;
    success &= func::abs(0) == 0;
    return success;
}

bool test_Q_sqrt()
{
    // TODO: Find threshold for Q_sqrt
    bool success = func::Q_sqrt(1) == 1;
    success &= func::Q_sqrt(2) == 1.4142135623730951;
    success &= func::Q_sqrt(3) == 1.7320508075688772;
    success &= func::Q_sqrt(4) == 2;
    success &= func::Q_sqrt(5) == 2.23606797749979;
    success &= func::Q_sqrt(6) == 2.449489742783178;
    success &= func::Q_sqrt(7) == 2.6457513110645907;
    return success;
}

bool test_Q_rsqrt()
{
    // TODO: Find threshold for Q_rsqrt
    bool success = func::Q_rsqrt(1) == 1;
    success &= func::Q_rsqrt(2) == 0.7071067811865476;
    success &= func::Q_rsqrt(3) == 0.5773502691896257;
    success &= func::Q_rsqrt(4) == 0.5;
    success &= func::Q_rsqrt(5) == 0.4472135954999579;
    success &= func::Q_rsqrt(6) == 0.408248290463863;
    success &= func::Q_rsqrt(7) == 0.3535533905932737;
    return success;
}

bool test_sqrt()
{
    bool success = func::sqrt(1) == 1;
    double x2[]{2, 3, 4, 5, 6, 7};
    for (double x : x2) {
        success &= (func::sqrt(x) - std::sqrt(x)) < 1e-15;
    }
    return success;
}

bool test_pow_long()
{
    bool success = func::pow(1L, 1) == 1;
    success &= func::pow(2L, 1) == 2;
    success &= func::pow(2L, 2) == 4;
    success &= func::pow(2L, 3) == 8;
    success &= func::pow(2L, 4) == 16;
    success &= func::pow(10L, 5) == 100000L;
    return success;
}

bool test_polynomial()
{
    double coeffs[] = {1, 2, 3, 4, 5};
    bool success = func::polynomial(2, coeffs, 5) == 129;
    return success;
}

Harness func_tests()
{
    Harness harness = Harness();
    harness.print_test_suite_name("Function Tests");
    harness.run_test(test_abs, "abs");
    harness.run_test(test_Q_sqrt, "Q_sqrt");
    harness.run_test(test_Q_rsqrt, "Q_rsqrt");
    harness.run_test(test_sqrt, "sqrt");
    harness.run_test(test_pow_long, "pow_long");
    harness.run_test(test_polynomial, "polynomial");
    harness.print_suite_result();
    return harness;
}