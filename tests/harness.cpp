//
// Created by mas on 4/17/22.
//

#include "harness.h"
#include <iostream>
#include <cstring>

void Harness::print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
        std::cout << " ";
}

void Harness::print_test_result(bool result)
{
    if (result)
        std::cout << "OK" << std::endl;
    else
        std::cout << "FAIL" << std::endl;
}

void Harness::print_test_result(bool result, const char *name)
{
    m_total++;
    m_passed += result;
    std::cout << name;
    // determine # of spaces to print
    int result_len = result ? 2 : 4;
    int spaces_to_print = m_width - (int)strlen(name) - result_len;
    print_spaces(spaces_to_print);
    print_test_result(result);
}

void Harness::print_test_suite_name(const char *name) const
{
    for (int i = 0; i < m_width; i++)
        std::cout << "*";
    std::cout << std::endl;
    int open_spaces = m_width - (int)strlen(name);
    int stars = open_spaces / 2 - 1;
    for (int i = 0; i < stars; i++)
        std::cout << "*";
    std::cout << " " << name << " ";
    for (int i = 0; i < stars; i++)
        std::cout << "*";
    std::cout << std::endl;
    for (int i = 0; i < m_width; i++)
        std::cout << "*";
    std::cout << std::endl;
}

void Harness::print_suite_result() const
{
    for (int i = 0; i < m_width; i++)
        std::cout << "-";
    std::cout << std::endl;
    std::cout << "Tests: " << m_total
              << " Passed: " << m_passed
              << " Failed: " << m_total - m_passed << std::endl;
}

void Harness::run_test(bool (*test_function)(), const char *name)
{
    print_test_result(test_function(), name);
}
