//
// Created by Sophie on 06.11.2021.
#pragma once

//препроцессорная директива,чтобы конкретный исходный файл при компиляции подключался строго один раз
//endif то же самое, только менее современный
class Matrix
{
private:
	int n;
	int m;
	double** matrix;

	class Row
	{
	private:
		double* row;
		int columns;
	public:
		Row(double* row, int columns);

		double& operator[](int j);
//        double operator[](int j) const{
//            if(0<=j && j<columns) return row[j];
//        }

	};

public:
	Matrix(int n = 1, int m = 1);

	Matrix(const Matrix& matrix, double num);

	Matrix(double number = 0);

	~Matrix();


	operator double();

	Matrix& operator=(const Matrix& matrix);

	friend Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);

	friend Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);

	friend Matrix operator-(const Matrix& matrix, double num);

	friend Matrix operator-(double num, const Matrix& matrix);

   Matrix& operator -(double num);


  Matrix& operator-(const Matrix &matrix2);



	Matrix& operator+=(double element);

	Row& operator[](int index);

	Row operator[](int index) const;


	bool operator==(const Matrix& matrix);

	bool operator!=(const Matrix& matrix);


	void fillMatrix();

	void printMatrix();
};