#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{
cout<<"sizeof: \n";
cout << "char\t" << sizeof(char) << endl;
cout << "short\t" << sizeof(short) << endl;
cout << "int\t" << sizeof(int) << endl;
cout << "long\t" << sizeof(long) << endl;
cout << "float\t" << sizeof(float) << endl;
cout << "double\t" << sizeof(double) << endl;
cout << "int*\t" << sizeof(int*) << endl;
cout << "double*\t" << sizeof(double*) << endl;
cout << "float*\t" << sizeof(float*) << endl;
cout << "long*\t" << sizeof(long*) << endl;

cout << "\nMatrix sizeof: \n";
Matrix<int> a(10);
Matrix<int> b(100);
Matrix<double> c(10);
Matrix<int,2> d(10,10);
Matrix<int,3> e(10,10,10);

cout << "1D int, 10 element a: " << sizeof(a) << endl;
cout << "1D int, 100 element b: " << sizeof(b) << endl;
cout << "1D double, 10 element c: " << sizeof(c) << endl;
cout << "2D int, 10x10 element d: " << sizeof(d) << endl;
cout << "3D int, 10x10x10 element e: " << sizeof(e) << endl;

cout << "\nNumber of elements:\n";
cout << "a:\t" << a.size() << endl;
cout << "b:\t" << b.size() << endl;
cout << "c:\t" << c.size() << endl;
cout << "d:\t" << d.size() << endl;
cout << "e:\t" << e.size() << endl;

int gyok;
while(cin >> gyok){
    if(sqrt(gyok) >= 0){
        cout << sqrt(gyok) << endl;
    }else{
        cout << "no square root.\n";
    }

}


/*int i;
while (cin >> i){
    errno = 0;
    double d = sqrt(i);
    if(errno == EDOM)
        cout << "no square root\n";
    else
        cout << d << endl;
}*/         // órai megoldás ez c++ specifikus azért érdekes


cin.clear();    //hibaüzeneteket kiüríti.
cin.ignore();   // kósza karaktert figyelmen kivűl hagyja. Tehát plusz enter ilyenek.

cout << "Enter 10 floating point values:!\n";
Matrix<double> m2(10);
double d2;
for (int i = 0; i < m2.size(); i++)
{
        cin >> d2;
        if(!cin) throw runtime_error("Problem reading from cin.");
        m2[i] = d2;
}
cout << "Matrix:\n" << m2 << endl;

cout << "\nMultiplication table\nEnter n: ";
int n,m3;
cin >> n;
cout << "Enter m: ";
cin >> m3;
Matrix<int,2> mtable(n,m3);
for (Index i = 0; i < mtable.dim1(); i++)
{
    for (Index j = 0; j < mtable.dim2(); j++)       // mátrix saját long tipusa lesz az index
    {
        mtable(i,j) = (i+1)*(j+1);
        cout << setw(5)  << mtable(i,j);             
    }
    cout << endl;
}

Matrix<complex<double>> m4(10);
cout << "\nEnter 10 complex numbers (Re, Im): ";
complex<double>comp;
for (int i = 0; i < 10; i++)
{
        cin >> comp;
        if(!cin) throw runtime_error("Problem reading from cin.");
        m4[i]=comp;
}
cout << "Complex matrix: " << m4 << endl;
complex<double> sum;
for (Index i = 0; i < m4.size(); i++)
{
    sum+=m4[i];
}
cout << "Sum: " << sum << endl;

Matrix<int,2> m5(2,3);
cout << "enter 6 int numbers" << endl;
for (int i=0;i<2;i++)
        for (int j=0;j<3;j++)
            cin>>m5(i,j);
    cout<<m5<<endl;
    
    for (int i=0;i<2;i++)
        {
        for (int j=0;j<3;j++)
            cout<<m5(i,j)<<' ';
        cout<<endl;
        }   
return 0;
}
catch(exception& e){
    cerr << "exception: " << e.what() << "\n";
    return 1;
}
catch(...){
    cerr << "Exception!\n";
    return 2;
}