#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	string filename,line,word;
	cout<<"�뽫�ļ��ϵ���������"<<endl;
	cin>>filename;
	ifstream in(filename);
	if(!in) {
		cout<<"�ļ���ʧ��"<<endl;
		return -1;
	}

	vector<string>words;
	while(getline(in,line)) {
		words.push_back(line);
	}

	for(auto c:words) {
		istringstream is(c);
		while(is>>word)
			cout<<word<<' ';
	}
	return 0;
}
