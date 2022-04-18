//
// Created by mas on 4/16/22.
//

#include <stdexcept>
#include "matrix.h"

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        rows = other.rows;
        cols = other.cols;
        m_data = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &other)
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrix sizes must be equal");
    }
    for (int i = 0; i < rows * cols; i++)
    {
        m_data[i] += other.m_data[i];
    }
    return *this;
}

Matrix &Matrix::operator+(const Matrix &other)
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrix sizes must be equal");
    }
    auto result = new Matrix(*this);
    *result += other;
    return *result;
}

Matrix &Matrix::operator-=(const Matrix &other)
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrix sizes must be equal");
    }
    for (int i = 0; i < rows * cols; i++)
    {
        m_data[i] -= other.m_data[i];
    }
    return *this;
}

Matrix &Matrix::operator-(const Matrix &other)
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrix sizes must be equal");
    }
    auto result = new Matrix(*this);
    *result -= other;
    return *result;
}

Matrix &Matrix::operator*=(const Matrix &other)
{
    if (cols != rows)
    {
        throw std::invalid_argument("Matrix sizes must be equal");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                result.m_data[i * other.cols + j] +=
                        m_data[i * cols + k]
                        * other.m_data[k * other.cols + j];
            }
        }
    }
    *this = result;
    return *this;
}

Matrix &Matrix::operator*=(double scalar)
{
    for (int i = 0; i < rows * cols; i++)
    {
        m_data[i] *= scalar;
    }
    return *this;

}

Matrix &Matrix::operator*(const Matrix &other)
{
    if (cols != rows)
    {
        throw std::invalid_argument("Matrix sizes must be equal");
    }
    auto result = new Matrix(*this);
    *result *= other;
    return *result;
}

Matrix &Matrix::operator*(double scalar)
{
    auto result = new Matrix(*this);
    *result *= scalar;
    return *result;
}

Matrix &Matrix::operator/=(double scalar)
{
    double scalar_inv = 1.0 / scalar;
    for (int i = 0; i < rows * cols; i++)
    {
        m_data[i] *= scalar_inv;
    }
    return *this;
}

Matrix &Matrix::operator/(double scalar)
{
    auto result = new Matrix(*this);
    *result /= scalar;
    return *result;
}

Matrix &Matrix::operator^(int power)
{
    if (rows != cols)
    {
        throw std::invalid_argument(
                "A^n is not defined for non-square matrices");
    }
    if (power == 0)
    {
        return identity();
    }
    if (power == 1)
    {
        return *new Matrix(*this);
    }
    auto result = new Matrix(*this);
    if (power > 1)
    {
        for (int i = 1; i < power; i++)
        {
            *result *= *this;
        }
    }
    for (int i = 1; i < power; i++)
    { *result *= *this; }
    return *result;
}

Matrix &Matrix::operator^(double power)
{
    // TODO
    throw std::invalid_argument("Not implemented");

    if (power < 0)
    {
        throw std::invalid_argument("Power must be non-negative");
    }
    if (power == 0.0)
    {
        return identity();
    }
    auto result = new Matrix(*this);
    return *result;
}


/*****************************************************************************/
/**************************** Comparisons ************************************/
/*****************************************************************************/

bool Matrix::operator==(const Matrix &other)
{
    if (rows != other.rows || cols != other.cols)
    {
        return false;
    }
    for (int i = 0; i < rows * cols; i++)
    {
        if (m_data[i] != other.m_data[i])
        {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other)
{
    return !(*this == other);
}

/*****************************************************************************/
/************************* Special Operations ********************************/
/*****************************************************************************/

Matrix &Matrix::transpose()
{
    auto result = new Matrix(cols, rows); // ignore warning
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result->m_data[j * rows + i] = m_data[i * cols + j];
        }
    }
    *this = *result;
    return *this;
}

Matrix &Matrix::identity() const
{
    if (rows != cols)
    {
        throw std::invalid_argument("Matrix must be square");
    }
    auto result = new Matrix(rows, cols);
    // array is already initialized to 0
    for (int i = 0; i < rows; i++)
    {
        result->m_data[i * cols + i] = 1;
    }
    return *result;
}