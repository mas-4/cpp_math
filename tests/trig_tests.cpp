//
// Created by mas on 4/17/22.
//

#include <cmath>
#include <iostream>
#include "trig_tests.h"
#include "trig.h"

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
    printf("Cosine\t\t%s\n", test_cosine() ? "PASS" : "FAIL");
}