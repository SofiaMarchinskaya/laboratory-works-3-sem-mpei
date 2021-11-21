//
// Created by Sophie on 06.11.2021.
//


class Matrix {
private:
    int n;
    int m;
    double **matrix;
public:
    Matrix(int n = 1, int m = 1);

    Matrix(const Matrix &matrix, double num);
    Matrix(double number=0);

    ~Matrix();


    operator double();

    void fillMatrix();

    void printMatrix();
};