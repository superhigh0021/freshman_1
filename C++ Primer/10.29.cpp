#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

int main(void) {
	string s;
	cin>>s;
	ifstream in(s);
	vector<string> v;
	istream_iterator<string> it(in), eof;
	ostream_iterator<string> ot(cout," ");
	while(it!=eof) {
		v.push_back(*it++);
	}
	cout<<"��ͨ�����"<<endl;
	for(auto c:v)
		cout<<c<<' ';
	cout<<endl<<"�����������"<<endl;
	copy(v.begin(),v.end(),ot);

	return 0;
}
