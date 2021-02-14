#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void myprint(int val) {
	cout<<val<<endl;
}
void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//1.
	vector<int>::iterator itBegin=v.begin();
	vector<int>::iterator itEnd = v.end();
	while(itBegin!=itEnd) {
		cout<<*itBegin<<endl;
		itBegin++;
	}

	//2.
	cout<<endl;
	for(vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
		cout<<*it<<endl;
	}
	//3.
	cout<<endl;
	for_each(v.begin(),v.end(),myprint);
}


int main(void) {
	test01();
	system("pause");
	return 0; 
}
