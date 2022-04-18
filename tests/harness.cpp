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

void Harness::print_test_result(bool result, bool error)
{
    if (result)
        std::cout << "OK" << std::endl;
    else if (error)
        std::cout << "ERROR" << std::endl;
    else
        std::cout << "FAIL" << std::endl;
}

void Harness::print_test_result(bool result, bool error, const char *name)
{
    m_total++;
    if (result && error)
        throw std::runtime_error("A test cannot both pass and error!");
    m_passed += result;
    m_error += error;
    std::cout << name;
    // determine # of spaces to print
    int result_len = result ? 2 : 4;
    if (error)
        result_len = 5;
    int spaces_to_print = m_width - (int)strlen(name) - result_len;
    print_spaces(spaces_to_print);
    print_test_result(result, error);
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
              << " | Passed: " << m_passed
              << " | Error: " << m_error
              << " | Failed: " << m_total - m_passed - m_error << std::endl;
}

void Harness::run_test(bool (*test_function)(), const char *name)
{
    try {
        print_test_result(test_function(), false, name);
    } catch (...) {
        print_test_result(false, true, name);
    }
}
