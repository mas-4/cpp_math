//
// Created by mas on 4/17/22.
//
#include <iostream>
#include "matrix_tests.h"
#include "matrix.h"
#include "printer.h"

bool test_matrix_instantiation()
{
    unsigned int rows = 2;
    unsigned int cols = 2;
    bool success = true;
    Matrix m(rows, cols);
    success = m.rows == rows && success;
    success = m.cols == rows && success;
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(1, 0) = 3;
    m(1, 1) = 4;
    success = success && m(0, 0) == 1;
    success = success && m(0, 1) == 2;
    success = success && m(1, 0) == 3;
    success = success && m(1, 1) == 4;
    return success;
}

bool test_matrix_instantiation_w_data()
{
    unsigned int rows = 3;
    unsigned int cols = 3;
    bool success = true;
    auto data = new double[rows * cols]{
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };
    Matrix m(rows, cols, data);
    success = m.rows == rows && success;
    success = m.cols == rows && success;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            success = success && m(i, j) == data[i * cols + j];
        }
    }
    delete[] data;
    return success;
}

bool test_matrix_addition() {
    unsigned int rows = 3;
    unsigned int cols = 3;
    bool success = true;
    auto data = new double[rows * cols]{
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };
    Matrix m1(rows, cols, data);
    auto data2 = new double[rows * cols]{
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };
    Matrix m2(rows, cols, data2);
    Matrix m3 = m1 + m2;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            success = success && m3(i, j) == 2 * data[i * cols + j];
        }
    }
    delete[] data;
    delete[] data2;
    return success;
}

bool test_matrix_subtraction() {
    unsigned int rows = 3;
    unsigned int cols = 3;
    bool success = true;
    auto data = new double[rows * cols]{
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };
    Matrix m1(rows, cols, data);
    auto data2 = new double[rows * cols]{
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };
    Matrix m2(rows, cols, data2);
    Matrix m3 = m1 - m2;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            success = success && m3(i, j) == 0;
        }
    }
    delete[] data;
    delete[] data2;
    return success;
}

bool test_matrix_multiplication() {
    unsigned int rows = 3;
    unsigned int cols = 3;
    bool success = true;
    auto data = new double[rows * cols]{
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
    };
    Matrix m1(rows, cols, data);
    auto data2 = new double[rows * cols]{
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
    };
    Matrix m2(rows, cols, data2);
    Matrix m3 = m1 * m2;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            success = success && m3(i, j) == data[i * cols + j];
        }
    }
    delete[] data;
    delete[] data2;
    return success;
}

bool test_scalar_multiplication() {
    unsigned int rows = 3;
    unsigned int cols = 3;
    bool success = true;
    auto data = new double[rows * cols]{
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    };
    Matrix m1(rows, cols, data);
    Matrix m2 = m1 * 2;
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            success = success && m2(i, j) == 2 * data[i * cols + j];
        }
    }
    delete[] data;
    return success;
}

void matrix_tests() {
    Printer printer = Printer();
    printer.print_test_suite_name("Matrix tests");
    printer.print_test_result(test_matrix_instantiation(), "Matrix " "instantiation");
    printer.print_test_result(test_matrix_instantiation_w_data(), "Matrix " "instantiation with data");
    printer.print_test_result(test_matrix_addition(), "Matrix addition");
    printer.print_test_result(test_matrix_subtraction(), "Matrix " "subtraction");
    printer.print_test_result(test_matrix_multiplication(), "Matrix " "multiplication");
    printer.print_test_result(test_scalar_multiplication(), "Scalar " "multiplication");
    printer.print_suite_result();
}
