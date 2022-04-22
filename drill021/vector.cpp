#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>
#include <list>

using namespace std;

struct Item{
	string name;
	int iid;
	double value;
	/*...*/
};

ostream& operator<<(ostream& os, Item& it)
{
    return os << it.name <<" "<<it.iid<<" "<<it.value<<"\n";
}

istream& operator>>(istream& is, Item& it)
{
    string ss;
    int ii;
    double dd;
    is>>ss>>ii>>dd;
    Item final_it {ss,ii,dd};
    it = final_it;
    return is;
}

template<typename C>
void write(C& c, string s)
{
    cout<<s<<"\n";
    for (auto p = c.begin();p!=c.end(); ++p)
        cout<<*p;
    cout<<"\n";
}

int main(){
vector<Item> vi;
string iname {"items.txt"};
    ifstream ist {iname};
    if (!ist) runtime_error("can't open input file "+ iname);

    for (Item it; ist >> it; ) vi.push_back(it);
    
    write(vi, "Original vector");

	string a,b;

	sort(vi.begin(),vi.end(),[](Item& a, Item& b){return a.name < b.name;});
	write(vi,"sort by name\n");

	int c=0; 
	int d=0;
	sort(vi.begin(),vi.end(),[](Item& c, Item& d){return c.iid < d.iid;});
	write(vi, "sort by iid\n");

	double e=0;
	double f=0;
	sort(vi.begin(),vi.end(),[](Item& e, Item& f){return e.value > f.value;});
	write(vi,"sort by value\n");

	Item horse{"horse shoe",99,12.34};
	Item canon{"Canon",9988,499.95};
	vi.insert(vi.begin(), horse);
	vi.insert(vi.begin(), canon);
	write(vi,"2 new item:\n");

	vi.erase(find_if(vi.begin(),vi.end(),[](Item& a){return a.name == "ask";}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item& a){return a.name == "gang";}));
	write(vi,"remove ask and gang\n");

	vi.erase(find_if(vi.begin(),vi.end(),[](Item& c){return c.iid == 7;}));
	vi.erase(find_if(vi.begin(),vi.end(),[](Item& c){return c.iid == 9;}));
	write(vi,"remove 7 and 9\n");

//egészet előről listával

	vector<Item> li;
string iname2 {"items.txt"};
    ifstream ist2 {iname2};
    if (!ist2) runtime_error("can't open input file "+ iname2);

    for (Item it; ist2 >> it; ) li.push_back(it);
    
    write(li, "Original vector");

	string a2,b2;

	sort(li.begin(),li.end(),[](Item& a2, Item& b2){return a2.name < b2.name;});
	write(li,"sort by name\n");

	int c2=0; 
	int d2=0;
	sort(li.begin(),li.end(),[](Item& c2, Item& d2){return c2.iid < d2.iid;});
	write(li, "sort by iid\n");

	double e2=0;
	double f2=0;
	sort(li.begin(),li.end(),[](Item& e2, Item& f2){return e2.value > f2.value;});
	write(li,"sort by value\n");

	Item horse2{"horse shoe",99,12.34};
	Item canon2{"Canon",9988,499.95};
	li.insert(li.begin(), horse2);
	li.insert(li.begin(), canon2);
	write(li,"2 new item:\n");

	li.erase(find_if(li.begin(),li.end(),[](Item& a2){return a2.name == "ask";}));
	li.erase(find_if(li.begin(),li.end(),[](Item& a2){return a2.name == "gang";}));
	write(li,"remove ask and gang\n");

	li.erase(find_if(li.begin(),li.end(),[](Item& c2){return c2.iid == 7;}));
	li.erase(find_if(li.begin(),li.end(),[](Item& c2){return c2.iid == 9;}));
	write(li,"remove 7 and 9\n");

}