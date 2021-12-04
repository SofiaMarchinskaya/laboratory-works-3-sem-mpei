#include "Matrix.h"
#include <iostream>
#include <stdexcept>

using namespace std;


Matrix::Matrix(int n, int m)
{
	this->n = n;
	this->m = m;
	matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[m];
}


Matrix::Matrix(const Matrix& matrix, double num)
{
	n = matrix.n;
	m = matrix.m;
	this->matrix = new double* [n];
	for (int i = 0; i < n; i++)
		this->matrix[i] = new double[m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			this->matrix[i][j] = matrix.matrix[i][j] + num;
		}

	}

}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::fillMatrix()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] = 1;
		}
	}
}

Matrix::Row::Row(double* row, int columns)
{
	this->row = row;
	this->columns = columns;
}

double& Matrix::Row::operator[](int j)
{
	if (0 <= j && j < columns) return row[j];
	else throw out_of_range("index is out of range");
}


void Matrix::printMatrix()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


}

Matrix::operator double()
{
	double sum = 0;
	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			sum += matrix[i][j];
			if (matrix[i][j] != 0)++count;
		}

	return sum / (n * m);

}

Matrix::Matrix(double number)
{
	n = 1;
	m = 1;
	matrix = new double* [n];
	matrix[0] = new double[m];
	matrix[0][0] = number;
}

//перегрузка операторов
Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (this == &matrix)                                              // Проверка на самоприсваивание
		return *this;
	this->~Matrix();
	n = matrix.n;
	m = matrix.m;
	this->matrix = new double* [n];
	for (int i = 0; i < n; i++)
		this->matrix[i] = new double[m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			this->matrix[i][j] = matrix.matrix[i][j];
		}

	}

	return *this;

}

//дружественные функции
Matrix operator+(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.n != matrix2.n || matrix1.m != matrix2.m)
	{
		throw runtime_error("an attempt to add matrices of different sizes");
	}
	int n = matrix1.n;
	int m = matrix1.m;
	Matrix* result = new Matrix(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			result->matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
		}
	}
	return *result;

}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2)
{
	if (matrix1.n != matrix2.n || matrix1.m != matrix2.m)
	{
		throw runtime_error("attempt to subtract matrices of different sizes");
	}
	int n = matrix1.n;
	int m = matrix1.m;
	Matrix* result = new Matrix(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			result->matrix[i][j] = matrix1.matrix[i][j] - matrix2.matrix[i][j];
		}
	}
	return *result;

}

//Matrix &Matrix::operator-(const Matrix &matrix2) {
//    Matrix *result = new Matrix(n, m);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; ++j) {
//            result->matrix[i][j] = this->matrix[i][j] - matrix2.matrix[i][j];
//        }
//    }
//    return *result;
//}

Matrix& Matrix::operator+=(double element)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] += element;
		}
	}
	return *this;
}


bool Matrix::operator==(const Matrix& matrix)
{
	if (n != matrix.n || m != matrix.m) return false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (this->matrix[i][j] != matrix.matrix[i][j])
				return false;

		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& matrix)
{
	if (n != matrix.n || m != matrix.m) return true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (this->matrix[i][j] != matrix.matrix[i][j])
				return true;

		}
	}
	return false;
}

Matrix::Row& Matrix::operator[](int index)
{
	if (0 <= index && index < n)
	{
		Row* r = new Row(matrix[index], m);
		return *r;
	}

}

Matrix::Row Matrix::operator[](int index) const
{
	if (0 <= index && index < n)
	{
		Row r(matrix[index], m);
		return r;
	}

}


//Matrix &Matrix::operator-(double d) {
//    Matrix *result = new Matrix(n, m);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; ++j) {
//            result->matrix[i][j] = this->matrix[i][j] - d;
//        }
//    }
//    return *result;
//}
Matrix operator-(double num, const Matrix& matrix)
{
	int n = matrix.n;
	int m = matrix.m;
	Matrix* result = new Matrix(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			result->matrix[i][j] = num - matrix.matrix[i][j];
		}
	}
	return *result;
}


Matrix operator-(const Matrix& matrix, double num)
{

	int n = matrix.n;
	int m = matrix.m;
	Matrix* result = new Matrix(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			result->matrix[i][j] = matrix.matrix[i][j] - num;
		}
	}
	return *result;
}



