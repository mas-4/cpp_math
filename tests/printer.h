//
// Created by mas on 4/17/22.
//

#ifndef MS_MATH_PRINTER_H
#define MS_MATH_PRINTER_H


class Printer
{
private:
    static Printer *instance;
    const int width = 80;
    int m_tests = 0;
    int m_passed = 0;
public:
    void print_spaces(int spaces);
    void print_test_suite_name(const char *name);
    void print_test_result(bool result);
    void print_test_result(bool result, const char *name);
    void print_suite_result();
};

#endif //MS_MATH_PRINTER_H
