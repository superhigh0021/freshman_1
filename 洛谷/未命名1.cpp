#include<iostream>
#include<fstream>
using namespace std;

int main(void) {
	string name,s;
	cin>>s;
	ifstream ifs;
	ifs.open(s);
	while(ifs>>name)
		cout<<name<<endl;

	return 0;
}
