//
// Created by mas on 4/17/22.
//

#include "test_funcs.h"
#include "func.h"

bool test_abs()
{
    bool success = func::abs(-1) == 1;
    success &= func::abs(1) == 1;
    success &= func::abs(0) == 0;
    return success;
}

Harness func_tests()
{
    Harness harness = Harness();
    harness.print_test_suite_name("Function Tests");
    harness.run_test(test_abs, "abs");
    harness.print_suite_result();
    return harness;
}