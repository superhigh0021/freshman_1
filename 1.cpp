#include<iostream>
#include<string>
#include<set>
#include<functional>
#include<algorithm>
#include<map>
using namespace std;
using namespace placeholders;

struct feb {
	template<typename T>
	bool operator()(T a,T b) {
		return *b<*a;
	}
};

int main(void) {
	auto f=[](string*a,string*b) {
		return *b<*a;
	};
	set<string*,feb>ssp;
	map<string*,int,feb>msp;
	ssp.insert(new string("Anteater"));
	ssp.insert(new string("Wombat"));
	ssp.insert(new string("Lemur"));
	ssp.insert(new string("Penguin"));
	for(auto i=ssp.begin(); i!=ssp.end(); ++i) {
		cout<<**i<<endl;
	}
	msp.insert(make_pair(new string("Anteater"),1));
	msp.insert(make_pair(new string("Wombat"),2));
	msp.insert(make_pair(new string("Lemur"),3));
	msp.insert(make_pair(new string("Penguin"),4));
	for(auto i:msp) {
		cout<<*(i.first)<<endl;
	}
	return 0;
}
