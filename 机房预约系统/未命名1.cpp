#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector<int>v;
	for(int i=1; i!=100; ++i) {
		v.push_back(i);
	}
	cout<<v.capacity()<<endl;
	v.shrink_to_fit();
	cout<<v.capacity()<<endl;
	
	return 0;
}
