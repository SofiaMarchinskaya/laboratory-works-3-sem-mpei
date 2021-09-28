#include <iostream>
#include <fstream>
#include <cmath>
//Определить в каком массиве меньше произведение элементов, попадающих в заданный диапазон.
// Если в двух или трёх массивах произведения совпадают, вывести соответствующее сообщение.
using namespace std;
const int nmax = 100;
double f(double i)
{
    return i;
}
void ArrayInput(int* n, double x[], char* fname, double* begin, double* end) {
    ifstream file(fname);

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
void ArrayOutput(int n, double x[], double a,double b,ofstream &fout){
    if(fout.is_open()){
        fout<<n<<endl;
        fout<<a<<" "<<b<<endl;
        for(int i = 0; i<n; i++){
            fout<<x[i]<<" ";
        }
        fout<<endl;
    }
    else throw exception("The file was not opened!");

}
double MultiplyRange(double x[], int n, double a, double b, bool &haveInRange,double (*pf)(double)){
    double res=1;
    for(int i = 0; i<n; i++){
        if(pf(x[i])>=a && pf(x[i])<=b){
            res*=pf(x[i]);
            haveInRange=true;
        }
    }
    return res;
}
int main(int argc, char* argv[]) {
    if (argc < 5) {
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
        }catch (exception &err){
            cout<<err.what()<<endl;
            return -1;
        }
        p1 = MultiplyRange(m1, n1, a1, b1, inRange1,f);
        p2 = MultiplyRange(m2, n2, a2, b2, inRange2,f);
        p3 = MultiplyRange(m3, n3, a3, b3, inRange3,f);
//        p1 = MultiplyRange(m1, n1, a1, b1, inRange1,abs);
//        p2 = MultiplyRange(m2, n2, a2, b2, inRange2,abs);
//        p3 = MultiplyRange(m3, n3, a3, b3, inRange3,abs);
        ofstream fout(argv[4]);
        ArrayOutput(n1, m1, a1, b1,fout);
        ArrayOutput(n2,m2,a2,b2,fout);
        ArrayOutput(n3,m3,a3,b3,fout);
        if (inRange1 && inRange2 && inRange3) {
            min = p1;
            if (p2 < min) min = p2;
            if (p3 < min) min = p3;

            if (p1 == min)
                fout<<"array 1 has the minimum product of elements: "<<min<<endl;
            if (p2 == min)
                fout<<"array 2 has the minimum product of elements: "<<min<<endl;
            if (p3 == min)
                fout<<"array 3 has the minimum product of elements: "<<min<<endl;
        } else
            fout<<"There are no elements from the range in some array"<<endl;
    }

    return 0;
}
