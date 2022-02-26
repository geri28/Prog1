// drill védésnél absztrakt osztály, tisztán virtuális és ami absztraktá teszi az osztályt és a child-okat
#include <iostream>
#include <string>

using namespace std;

class B1{
    public:
        virtual void vf(){cout <<"B1::vf()"<<endl;}
        void f() {cout << "B1::f()" <<endl;}
        virtual void pvf() = 0; // tisztán virtuális függvény, azért absztrakt mert 0 lett és így egész osztály absztrakt lett(tisztán virtuális)

};
class D1 : public B1{
    public:
        void vf(){ cout << "D1::vf()" <<endl;}
        void f() {cout << "D1::f()" <<endl;}

};

class D2 : public D1{
    public: 
        void pvf(){cout << "D2::pvf()"<<endl;}

};

class B2{
    public: 
        virtual void pvf() = 0;
};

class D21 : public B2{
    public:
    string s = "D21::pvf()";
        void pvf(){cout << s <<endl;}
};

class D22 : public D21{
    public:
        int n = 3;
        void pvf(){cout << n << endl;}
};

void f(B2& b2){
    b2.pvf();
};

int main(){
    /*B1 b1;
    b1.vf();
    b1.f();
    D1 d1;
    d1.vf();
    d1.f();
    d1.f();
    d1.f();
    d1.f();
    d1.f();
    B1& b1ref = d1;
    b1ref.vf();
    b1ref.f();*/

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    D21 d21;
    // vagy ha üres d21.s = "d21.s";
    d21.pvf();
    f(d21);

    D22 d22;
    // vagy ha üres d22.n = 10;
    d22.pvf();
    f(d22);
}