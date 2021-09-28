#include <iostream>
#include <fstream>
//Даны две матрицы разного размера.
// Для той из матриц, в которой есть элементы, равные 0,
// найти среднее арифметическое положительных элементов в каждой строке.
using namespace std;
const int nmax = 100;
//Функция ввода матрицы из файла
void MatrixInput(int* n,int*m, double x[][nmax], char* fname) {
    ifstream file(fname);
    if (file.is_open()) {
        cout << "file is opened: " << fname << endl;
        file >> *n>>*m;
        if(*n>nmax||*n<=0||*m>nmax||*m<=0){
            throw exception("An incorrect number of elements was entered!");
        }

        for (int i = 0; i < *n; i++) {
            for(int j = 0; j<*m;j++){
                file >> x[i][j];
            }
        }
        file.close();
    }
    else throw exception("The file was not opened!");

}
//функция, проверяющая наличие нулевых элементов в матрице
bool haveZeros(double x[][nmax],  int n, int m){
    for(int i = 0; i<n;i++){
        for(int j = 0;j<m;j++){
            if(x[i][j]==0){
                return true;
            }
        }
    }
    return false;
}
//функция, возвращающая среднее арифметическое положительных элементов в строке матрицы
double arithmeticOfPositive(int m, double x[]) {
    double result = 0;
    int c = 0;
    for(int i =0; i<m;i++){
        if(x[i]>0){
            result+=x[i];
            c++;
        }
    }
    if(c>0) return result/c;
    return 0;
}
void ArrayOutput(int n,int m, double x[][nmax]) {
    cout<<"Matrix "<<n<<"x"<<m<<": "<<endl;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "more parameters are required" << endl;
    } else {
        double matrix1[nmax][nmax];
        double matrix2[nmax][nmax];
        int n1, n2,m1,m2;
        double a;
        try {
            MatrixInput(&n1,&m1, matrix1, argv[1]);
            MatrixInput(&n2,&m2, matrix2, argv[2]);
        }catch (exception err){
            cout<<err.what()<<endl;
            return -1;
        }
        ArrayOutput(n1,m1,matrix1);
        ArrayOutput(n2,m2,matrix2);
        cout<<"Matrix 1: "<<endl;
        if(haveZeros(matrix1,n1,m1)){
            for(int i = 0; i<n1;i++){
                a= arithmeticOfPositive(m1,matrix1[i]);
                if(a>0){
                    cout<<"the arithmetic mean in the line number "<<i+1<<": "<<a<<endl;
                } else cout<<"there are no positive elements in line number "<<i+1<<endl;
            }
        }
        else{
            cout<<"there are no zeros in matrix number 1"<<endl;
        }
        cout<<"Matrix 2: "<<endl;
        if(haveZeros(matrix2,n2,m2)){
            for(int i = 0; i<n2;i++){
                a= arithmeticOfPositive(m2,matrix2[i]);
                if(a>0){
                    cout<<"the arithmetic mean in the line number "<<i+1<<": "<<a<<endl;
                } else cout<<"there are no positive elements in line number "<<i+1<<endl;
            }
        }
        else{
            cout<<"there are no zeros in matrix number 2"<<endl;
        }

    }


    return 0;
}
