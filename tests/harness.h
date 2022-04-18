//
// Created by mas on 4/17/22.
//

#ifndef MS_MATH_HARNESS_H
#define MS_MATH_HARNESS_H


class Harness
{
private:
    const int m_width = 80;
public:
    int m_total = 0;
    int m_passed = 0;
    int m_error = 0;
    static void print_spaces(int spaces);
    void print_test_suite_name(const char *name) const;
    static void print_test_result(bool result, bool error);
    void print_test_result(bool result, bool error, const char *name);
    void print_suite_result() const;
    void run_test(bool (*test_function)(), const char *name);
};

#endif //MS_MATH_HARNESS_H
