//
// Created by mas on 4/17/22.
//

#ifndef MS_MATH_HARNESS_H
#define MS_MATH_HARNESS_H


class Harness
{
private:
    static Harness *instance;
    const int width = 80;
    int m_tests = 0;
    int m_passed = 0;
public:
    static void print_spaces(int spaces);
    void print_test_suite_name(const char *name) const;
    static void print_test_result(bool result);
    void print_test_result(bool result, const char *name);
    void print_suite_result() const;
    void run_test(bool (*test_function)(), const char *name);
};

#endif //MS_MATH_HARNESS_H
