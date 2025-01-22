#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
protected:
    int row;
    int col;
    //double *matrix_data = new double[row][col];
    double **matrix_data;
public:
    Matrix(int m, int n);

    ~Matrix() {
        delete[] matrix_data;
    }

    double get(int row, int col) const;
    void set(int row, int col, double value);

    int getRows() const;
    int getColumns() const;

    friend ostream& operator<<(ostream& os, const Matrix& mat);
    //Matrix& operato+=(const Matrix& rhs)

    Matrix(const Matrix & rhs);
    Matrix& operator=(Matrix other);

    Matrix& operator+=(const Matrix & xyz);
    Matrix operator+(const Matrix & abc);
    //Matrix operator+(const Matrix& lhs, const Matrix& rhs);

};


//void sumMatrixes(Matrix& A, Matrix& B);