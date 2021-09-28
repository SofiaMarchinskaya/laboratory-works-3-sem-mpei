#include <iostream>
#include <fstream>
//Определить в каком массиве меньше произведение элементов, попадающих в заданный диапазон.
// Если в двух или трёх массивах произведения совпадают, вывести соответствующее сообщение.
using namespace std;
const int nmax = 100;
//подпрограмма ввода массива
void ArrayInput(int* n, double x[], char* fname, double* begin, double* end) {
    ifstream file(fname);//поток файлового ввода

    if (file.is_open()) {
        cout << "file is opened: " << fname << endl;
        file >> *n;
        if(*n>nmax||*n<=0){
            throw exception("An incorrect number of elements was entered!");
        }
        file >> *begin >> *end;
        if(*begin>*end){
            throw exception("An incorrect range was entered!");
        }
        for (int i = 0; i < *n; i++) {
            file >> x[i];
        }
        file.close();
    }
    else throw exception("The file was not opened!");

}
//подпрограмма вывода массива и связанных с ним данных
//а,b - границы диапазона
void ArrayOutput(int n, double x[], double a,double b){
    cout<<n<<endl;
    cout<<a<<" "<<b<<endl;
    for(int i = 0; i<n; i++){
        cout<<x[i]<<" ";
    }
}
//функция, вычисляющая произведение элементов строки, входящих в заданный диапазон a b
double MultiplyRange(double x[], int n, double a, double b, bool &haveInRange){
    double res=1;//результат произведения
    for(int i = 0; i<n; i++){
        if(x[i]>=a && x[i]<=b){//проверка вхождения в диапазон
            res*=x[i];
            haveInRange=true;//проверка наличия таких элементов в строке
        }
    }
    return res;
}
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "more parameters are required" << endl;
    } else {
        double m1[nmax];
        double m2[nmax];
        double m3[nmax];
        int n1, n2, n3;
        double a1, b1, a2, b2, a3, b3;
        double p1, p2, p3, min;
        bool inRange1= false;
        bool inRange2= false;
        bool inRange3= false;
        try {
            ArrayInput(&n1, m1, argv[1], &a1, &b1);
            ArrayInput(&n2, m2, argv[2], &a2, &b2);
            ArrayInput(&n3, m3, argv[3], &a3, &b3);
        }catch (exception err){
            cout<<err.what()<<endl;
            return -1;
        }
        p1 = MultiplyRange(m1, n1, a1, b1, inRange1);
        p2 = MultiplyRange(m2, n2, a2, b2, inRange2);
        p3 = MultiplyRange(m3, n3, a3, b3, inRange3);
        cout<<"Input data:"<<endl;
        ArrayOutput(n1,m1,a1,b1);
        cout<<endl;
        ArrayOutput(n2,m2,a2,b2);
        cout<<endl;
        ArrayOutput(n3,m3,a3,b3);
        cout<<endl;
        if (inRange1 && inRange2 && inRange3) {
            min = p1;
            if (p2 < min) min = p2;
            if (p3 < min) min = p3;

            if (p1 == min)
                printf("array 1 has the minimum product of elements: %9.3lf\n", min);
            if (p2 == min)
                printf("array 2 has the minimum product of elements: %9.3lf\n", min);
            if (p3 == min)
                printf("array 3 has the minimum product of elements: %9.3lf\n", min);
        } else
            cout<<"There are no elements from the range in some array"<<endl;
    }

    return 0;
}
