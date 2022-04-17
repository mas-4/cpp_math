//
// Created by mas on 4/17/22.
//

#ifndef MS_MATH_PRINTER_H
#define MS_MATH_PRINTER_H


class Printer
        // determines how many tabs to print for a given test name
{
public:
    static const int width = 80;
    static void print_spaces(int spaces);
    static void print_test_suite_name(const char *name);
    static void print_test_result(bool result);
    static void print_test_result(bool result, const char *name);
};

#endif //MS_MATH_PRINTER_H
