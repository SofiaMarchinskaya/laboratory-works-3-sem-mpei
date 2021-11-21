#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    int n, m;
    cout << "Enter matrix values " << endl;
    cin >> n >> m;
    Matrix matrix(n, m);//создали объект размером nxm
    matrix.fillMatrix();//заполнили матрицу
    matrix.printMatrix();//распечатали на экран

    Matrix m2 = 10.0;//использование конструктора преобразования
    m2.printMatrix();
    double from_matrix = matrix;//преобразование матрицы в число
    cout<<from_matrix<<endl;


    Matrix *m3 = new Matrix(matrix,10.0);
    delete m3;
    return 0;
}
