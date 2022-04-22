#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>
#include <list>

using namespace std;
void fill_vec(istream& is, vector<double>& vec_d)
{
	for (double d; is >> d; ) vec_d.push_back(d);
}

int main()
try{

	vector<double> vd;
	string iname("vector.txt");
	ifstream ist{iname};
	if(!ist) runtime_error("cant open input file"+iname);
	fill_vec(ist,vd);

	cout << "elements: \n";
	for(double a : vd){
		cout << a << endl;
	}

	vector<int> vi (vd.size());
    copy(vd.begin(),vd.end(),vi.begin());

    double sum =0;
    for (int i = 0; i < vd.size(); ++i)
    {
    	cout << vd[i] << " " << vi[i] << endl;
    	sum += vd[i];
    }
    cout << sum;

    double vi_sum =0;
    for (int i = 0; i < vi.size(); ++i)
    {
    	vi_sum += vi[i];
    }
    cout << vi_sum << endl;
    cout<<"vd-vi difference: "<<sum-vi_sum<<endl;

    reverse(vd.begin(),vd.end());
    cout<<"Reverse:\n";
    for(double x : vd)
    	cout<<x<<"\n";

    double mean = sum/vd.size();
    cout << "mean: "<< mean << endl;

     vector<double> vd2;
    copy_if(vd.begin(),vd.end(),back_inserter(vd2),
    	[mean](auto& vd_entry){ return vd_entry<mean;});
    cout<<"vd2 elements:\n";
    for(double x : vd2)
    	cout<<x<<endl;

    sort(vd.begin(),vd.end());
    cout<<"vd sort:\n";
    for(double x : vd)
    	cout<<x<<"\n";

	return 0;

}
catch(exception& e){
	cerr << " Exception error: "<< e.what() <<	endl;
	return 1;
}
catch(...){
	cerr << "Exception" << endl;
	return 2;
}