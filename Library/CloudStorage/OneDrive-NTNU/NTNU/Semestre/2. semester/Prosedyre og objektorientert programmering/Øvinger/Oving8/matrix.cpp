#include "matrix.h"

Matrix::Matrix(int m, int n) : row{m}, col{n} {
    matrix_data = new double* [m];

    for(int i = 0; i < m; i++) {
        matrix_data[i] = new double[n];
        for(int j = 0; j < n; j++) {
            matrix_data[i][j] = 0.0;
            //cout << matrix_data[i][j] << endl;
        }
    }
}
void Matrix::set(int row, int col, double value) {
    matrix_data[row-1][col-1] = value;
}    

double Matrix::get(int row, int col) const {
    return matrix_data[row-1][col-1];
}

int Matrix::getRows() const {
    return Matrix::row;
}

int Matrix::getColumns() const {
    return Matrix::col;
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    for(int i = 0; i < mat.getRows(); i++) {
        for(int j = 0; j < mat.getColumns(); j++) {
            os << fixed << setprecision(1) << mat.matrix_data[i][j] << " ";
            //os << mat.get(i,j) << " " << endl;
        }
        os << endl;
    }
    return os;
}


Matrix::Matrix(const Matrix & rhs) {
    matrix_data = new double*[row];
    for(int i = 0; i < rhs.getRows(); i++) {
        matrix_data[i] = new double[col];
        for(int j = 0; j < rhs.getColumns(); j++) {
            matrix_data[i][j] = rhs.matrix_data[i][j];
            cout << matrix_data[i][j] << endl;
        }
    }
}

Matrix& Matrix::operator=(Matrix other) {
    swap(row, other.row);
    swap(col,other.col);
    swap(matrix_data, other.matrix_data);
    return *this;
}


void sumMatrixes(Matrix& A, Matrix& B) {
    if(A.getRows() != B.getRows() or A.getColumns() != B.getColumns()) {
        cout << "Ikke riktige dimensjoner";
        return;
    }
    else {
        Matrix C(A.getRows(),A.getColumns());

        for(int i = 0; i < A.getRows(); i++) {
            for(int j = 0; j < A.getColumns(); j++) {
                
            }
        }
    }
}

Matrix& Matrix::operator+=(const Matrix & xyz) {
    if (row != xyz.row || col != xyz.col) {
        throw invalid_argument("Matrisene har ikke like dimensjoner");
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix_data[i][j] += xyz.matrix_data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix & abc) {
    if (row != abc.row || col != abc.col) {
        throw invalid_argument("Matrisene har ikke like dimensjoner");
    }

    Matrix result(row,col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.matrix_data[i][j] = matrix_data[i][j] + abc.matrix_data[i][j];
        }
    }
    return result;


}