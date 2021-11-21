#include "Matrix.h"
#include <iostream>

using namespace std;


Matrix::Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    matrix = new double *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new double[m];
}


Matrix::Matrix(const Matrix &matrix, double num) {
    n = matrix.n;
    m = matrix.m;
    this->matrix = new double *[n];
    for (int i = 0; i < n; i++)
        this->matrix[i] = new double[m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->matrix[i][j] = matrix.matrix[i][j] + num;
        }

    }

}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::fillMatrix() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = 1;
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}

Matrix::operator double() {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            sum += matrix[i][j];
            if (matrix[i][j] != 0)++count;
        }

    return sum / (n * m);

}

Matrix::Matrix(double number) {
    n=1;
    m=1;
    matrix=new double*[n];
    matrix[0] = new double[m];
    matrix[0][0] = number;
}


