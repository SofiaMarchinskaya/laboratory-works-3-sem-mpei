#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	Matrix m1(2, 2);
	Matrix m2(2, 2);
	Matrix m3(2, 3);
	Matrix m4(2, 2);


	m1.fillMatrix();
	m2.fillMatrix();
	m3.fillMatrix();
	m4.fillMatrix();


	m4 = 1.0 - m2;

	m4.printMatrix();

	m4.fillMatrix();

	m4 = m2 - 1.0;

	m4.printMatrix();

	return 0;
}
