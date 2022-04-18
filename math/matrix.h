//
// Created by mas on 4/16/22.
//

#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H


class Matrix
{
private:
    double *m_data;
public:
    unsigned int rows;
    unsigned int cols;

    Matrix(unsigned int rows, unsigned int cols)
            : rows(rows), cols(cols), m_data(new double[rows * cols]{0})
    {};

    Matrix(unsigned int rows, unsigned int cols, double *data)
            : rows(rows), cols(cols), m_data(new double[rows * cols]{0})
    {
        for (unsigned int i = 0; i < rows * cols; i++)
            m_data[i] = data[i];
    };

    Matrix(const Matrix &other)
            : rows(other.rows),
              cols(other.cols),
              m_data(new double[other.rows * other.cols]{0})
    {
        for (unsigned int i = 0; i < rows * cols; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }

    ~Matrix()
    {
        delete[] m_data;
    };

    double &operator()(unsigned int i, unsigned int j)
    {
        return m_data[i * cols + j];
    }

    double *operator[](int i)
    {
        return m_data + i * cols;
    }

    Matrix &operator=(const Matrix &other);

    Matrix &operator+=(const Matrix &other);

    Matrix &operator+(const Matrix &other);

    Matrix &operator-=(const Matrix &other);

    Matrix &operator-(const Matrix &other);

    Matrix &operator*=(const Matrix &other);

    Matrix &operator*=(double scalar);

    Matrix &operator*(const Matrix &other);

    Matrix &operator*(double scalar);

    Matrix &operator/=(double scalar);

    Matrix &operator/(double scalar);

    Matrix &operator^(int power);

    Matrix &operator^(double power);

    bool operator==(const Matrix &other);

    bool operator!=(const Matrix &other);

    Matrix &transpose();

    Matrix &identity() const;
};

#endif //MATH_MATRIX_H
