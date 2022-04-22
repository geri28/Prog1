//map<int,string> (kulcs-értékpárok)      int és string párba állnak tehát int[0] párja a string[0]

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <stdexcept>
using namespace std;

void read_map(map<string,int>& m){
    string s;
    int i = 0;

    while(m.size()<10){
        cin>>s>>i;
        //m[s] = i; vagy
        m.insert(make_pair(s, i));
    }
}


template<typename K, typename V>
void print(const map<K,V>& m){
    int su = 0;
    for(pair<K,V> a : m){
    //for(auto& a : m){     //ha auto van akkor ott biztos megkérdezi védésnél milyen tipusu lesz
        cout << a.first << '\t' << a.second << endl;
    //    su += a.second;
    }
   // cout << "értékek összege: " << su << endl;      //ez csak gagyi tipusnál működik amúgy lambda lesz
    // int total =  accumulate(msi.begin(),msi.end(), 0,[](int sum, const pair<string, int>& p){return sum += p.second}); Na ez a tuti
}


int main()
try{
    map<string, int> msi;
msi["a"] = 1;
msi["b"] = 2;
msi["c"] = 3;
msi["abc"] = 4;
msi["g"] = 53;
msi["wert"] = 92;
msi["huh"] = 23;
msi["k"] = 19;
msi["alma"] = 99;
msi["t"] = 100;

print(msi);
msi.erase("a");
cout << "a törlése után" << endl;
print(msi);
//msi.erase(msi.begin(), msi.end());
cout << "Teljes törlés után" << endl;
print(msi);


cout << "10 név érték pár megadása: "<<endl;
//read_map(msi);
cout << "msi: " <<endl;
print(msi);

map<int,string>mis;
for(pair<string,int> a : msi){
    mis[a.second] = a.first;
   //   vagy     mis.insert(make_pair(a.second,a.first));
}
cout << "új cucc" << endl;
print(mis);

}


catch(exception& e) {
    cerr << "Exception: " <<e.what() << "\n";
    return 1;
}
catch(...){
    cerr << "Exception" << "\n";
    return 2;
}

