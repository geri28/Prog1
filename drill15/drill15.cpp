#include <iostream>
#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
class Person{
    public:
            Person(){};
            Person(string f, string l, int a):f{f}, l{l},a{a}{
                if(a<0||a>=150){
                    throw runtime_error("Invalid age");
                }
                string n = f+l;
                for(int i=0; i <= n.length(); i++){
                if(n[i]==';' || n[i]==':' || n[i]=='"'  || n[i]=='['||n[i]==']'||n[i]=='*'||n[i]=='&'||n[i]=='^'||n[i]=='%'||n[i]=='$'||n[i]=='#'||n[i]=='@'|| n[i]=='!'){
                     throw runtime_error("Invalid name");
                }
            }
            //vagy
            /*
            for(int i=0; i <= n.length(); i++){
                switch(n[i]){
                    case(';'):
                    case(':'):
                    ...
                        thwo runtime_error("invalid name");
                        break;
                        default:
                        break;
                }
            }*/
            };
            //string name()const{return n;}
            string first_name()const{return f;}
            string last_name()const{return l;}
            int age()const{return a;}
    private:
                int a;
               // string n;
            string f;
            string l;
          /* string name = "";
            int age=0;
            Person(string n,int a): name("Goofy"), age(63){};*/
        
};

ostream&/*output stream*/ operator<< (ostream& os, const Person& p){ // bineáris paraméter ha 2 vagy több paramétere van egyébként ?buneáris?
    return os << p.first_name() << " " << p.last_name() << " " << p.age();
}


istream& operator>> (istream& is,Person& p){
    string f;
    string l;
    int a;
    is >> f >> l >> a;

    p = Person(f,l,a);
    return is;
}

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
//add a cosine to slope:
double sloping_cos(double x){return cos(x)+slope(x);}

int main(){
	try{
		Point t1{100,100};
		Simple_window win(t1,600,600,"Function graphs");


		Axis x {Axis::x,Point{100,300},400,20,"x: 1 = = 20 pixels"};
    	Axis y {Axis::y,Point{300,500},400,20,"y: 1 = = 20 pixels"};
    	x.set_color(Color::red);
    	y.set_color(Color::red);
	    win.attach(x);
    	win.attach(y);
		win.wait_for_button();

		Point origo{600/2,600/2};
		Function f{one,-10,11,origo,400,20,20};
		win.attach(f);

		Function f_slope {slope,-10,11,origo,400,20,20};
	Text slope_label {Point{100,(600/2)+5*20},"x/2"};
	win.attach(f_slope);
	win.attach(slope_label);

		Function f_square {square,-10,11,origo,400,20,20};
	win.attach(f_square);

		Function f_cos {cos,-10,10,origo,400,20,20};
	f_cos.set_color(Color::blue);
	win.attach(f_cos);

		Function f_sloping_cos {sloping_cos,-10,11,origo,400,20,20};
	win.attach(f_sloping_cos);

    win.wait_for_button();

    //Person p;
    Person p("Goofy","Lajos", 63);
   // p.n="Goofy";
   // p.a=63;
    cout << p.first_name() << " "<< p.last_name() << " " << p.age() << endl;

    Person p2;
    cin >> p2;
    cout << p2 <<endl ;

    vector<Person> vec;
    for(Person p; cin>>p;){ // vagy while(cin>>p)
        if(p.first_name() == "end")break;
        vec.push_back(p);
    }
    for(Person p:vec){
        cout << p << endl;
    }

	}
	catch(exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	}
	catch(...){
		cerr << "error:\n";
		return 2;
	}

}