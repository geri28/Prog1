#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T> struct S{
    S(T vv= 0):val{vv}{}
    T& get();
    //paramétert adunk constnak
    const T& get() const;

    //void set(T new_t);
    void set(const T& new_T);
    //void operator=(const T&);
    T& operator=(const T&);
    void read_val(T& v);
private:
    T val;

};

template<typename T>
T& S<T>::get(){
    return val;
};

template<typename T> T& S<T>::operator=(const T& s){
    val = s;
    return val;
};

template<typename T>
const T& S<T>::get() const{
    return val;
};

template<typename T> void read_val(T& v){
    cin >> v;
};

template<typename T> void S<T>::set(const T& new_T){val=new_T;};

template<typename T> std::ostream& operator<<(ostream& os, vector<T>& v){
    os << "{";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << (i < v.size()-1 ? "," :" ");
    }
    os << "}" << endl;
    return os;
    
}
template<typename T> istream& operator>>(istream& is, vector<T>& v){
    char ch = 0;
    is >> ch;
    if( ch != '{'){
        is.unget();
        return is;
    }
    for (T val; is >> val;){
        v.push_back(val);
        is >> ch;
        if(ch!=',')break;
    }
    return is;
    
};


int main(){
    S<int> s;
    S<int> si {37};
    S<char> sc{'c'};
    S<double> sd{3.2};
    S<std::string> ss{"hello"};
    S<vector<int>> svi{std::vector<int>{1,1,2,3,5,8}};

    cout<< "S<int> : " << s.get() << endl;
    cout<< "S<int> : " << si.get() << endl;
    cout<< "S<char> : " << sc.get() << endl;
    cout<< "S<double> : " << sd.get() << endl;
    cout<< "S<string> : " << ss.get() << endl;
    for(auto& a: svi.get()){        //foreach ciklus
    cout << a << ' ';
}
  //  cout<< "S<vector> :" << svi.val << endl;

si.set(11);
sc.set('s');
sd.set(3.14);
vector<int> v {1,1,2,3,5,8};
v[0] = 45;
svi.set(v);

cout << si.get() << endl;
cout << sc.get() << endl;
cout << sd.get() << endl;
for(auto& a: svi.get()){        //foreach ciklus
    cout << a << ' ';
}
cout << endl;

si = 30;        //operator= miatt értelmezhető

cout << si.get() << endl;

int ii;
read_val(ii);
S<int>si2{ii};

double dd;
read_val(dd);
S<double>sd2{dd};

string str;
read_val(str);
S<string>ss2{str};

    cout<< "S<int> : " << si2.get() << endl;
    cout<< "S<double> : " << sd2.get() << endl;
    cout<< "S<string> : " << ss2.get() << endl;


    vector<int> vec;
    read_val(vec);
    S<vector<int>> svec{vec};     
    cout << "S<vector> :" <<svec.get() << endl;

}