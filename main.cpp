#include <iostream>

#include "tests/matrix_tests.h"
#include "tests/trig_tests.h"
#include "tests/test_funcs.h"

int main()
{
    Harness matrix_results = matrix_tests();
    Harness trig_results = trig_tests();
    Harness func_results = func_tests();
    int total_passed = matrix_results.m_passed
            + trig_results.m_passed
            + func_results.m_passed;
    int total_tests = matrix_results.m_total
            + trig_results.m_total
            + func_results.m_total;
    int total_failed = total_tests - total_passed;
    for (int i = 0; i < 80; i++)
        std::cout << '=';
    std::cout << std::endl;
    std::cout << "Total tests: " << total_tests << std::endl;
    std::cout << "Total passed: " << total_passed << std::endl;
    std::cout << "Total failed: " << total_failed << std::endl;
    int exit_code = total_passed != total_tests;
    return exit_code;
}
