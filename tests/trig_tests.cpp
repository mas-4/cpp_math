//
// Created by mas on 4/17/22.
//

#include <cmath>
#include <iostream>
#include "trig_tests.h"
#include "trig.h"
#include "printer.h"

bool test_cosine() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = cos(angle);
        double actual = trig::cos(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("cos(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

void trig_tests() {
    Printer printer = Printer();
    printer.print_test_suite_name("Trig Tests");
    printer.print_test_result(test_cosine(), "Cosine");
    printer.print_suite_result();
}