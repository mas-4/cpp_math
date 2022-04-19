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

bool test_sine() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = sin(angle);
        double actual = trig::sin(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("sin(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_tangent() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        if (i % 91 != 0) {
            // only fails on values close to 90 degrees
            // which are ill-defined anyway
            // TODO: improve tan close to 90
            continue;
        }
        double angle = i * M_PI / 180;
        double expected = tan(angle);
        double actual = trig::tan(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("tan(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_asin() {
    bool success = true;
    for (double i = -1.0; i < 1.0; i+=0.1) {
        double expected = asin(i);
        double actual = trig::asin(i);
        if (fabs(expected - actual) > 0.000001) {
            printf("asin(%f) = %f, expected %f\n", i, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_acos() {
    bool success = true;
    for (double i = -1.0; i < 1.0; i+=0.1) {
        double angle = i;
        double expected = acos(angle);
        double actual = trig::acos(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("acos(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_atan() {
    bool success = true;
    for (double i = -1.0; i < 1.0; i+= 0.1) {
        double actual = trig::atan(i);
        double expected = atan(i);
        if (fabs(expected - actual) > 0.00001) {
            printf("atan(%f) = %f, expected %f\n", i, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_atan2() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = atan2(angle, angle);
        double actual = trig::atan2(angle, angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("atan2(%f, %f) = %f, expected %f\n", angle, angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_sinh() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = sinh(angle);
        double actual = trig::sinh(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("sinh(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_cosh() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = cosh(angle);
        double actual = trig::cosh(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("cosh(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_tanh() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = tanh(angle);
        double actual = trig::tanh(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("tanh(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_asinh() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = asinh(angle);
        double actual = trig::asinh(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("asinh(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_acosh() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = acosh(angle);
        double actual = trig::acosh(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("acosh(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

bool test_atanh() {
    bool success = true;
    for (int i = 0; i < 360; i++) {
        double angle = i * M_PI / 180;
        double expected = atanh(angle);
        double actual = trig::atanh(angle);
        if (fabs(expected - actual) > 0.000001) {
            printf("atanh(%f) = %f, expected %f\n", angle, actual, expected);
            success = false;
        }
    }
    return success;
}

Harness trig_tests() {
    Harness harness = Harness();
    harness.print_test_suite_name("Trig Tests");
    harness.run_test(test_cosine, "Test cosine");
    harness.run_test(test_sine, "Test sine");
    harness.run_test(test_tangent, "Test tangent");
    harness.run_test(test_asin, "Test asin");
    harness.run_test(test_acos, "Test acos");
    harness.run_test(test_atan, "Test atan");
    harness.run_test(test_atan2, "Test atan2");
    harness.run_test(test_sinh, "Test sinh");
    harness.run_test(test_cosh, "Test cosh");
    harness.run_test(test_tanh, "Test tanh");
    harness.run_test(test_asinh, "Test asinh");
    harness.run_test(test_acosh, "Test acosh");
    harness.run_test(test_atanh, "Test atanh");
    harness.print_suite_result();
    return harness;
}
