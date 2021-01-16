#include<iostream>
using namespace std;

int main(void) {
	int b,a[10]= {10,20,30,40,50,60,70,80,90,100};
	cout<<"请键入一个10~100的数"<<endl;
	cin>>b;
	for(int i=0; i<10; ++i) {
		if(a[i]<b&&a[i+1]>=b) {
			for(int j=9; j>i+1; --j)
				a[j]=a[j-1];
			a[i+1]=b;
		}
	}
	for(auto c:a)
		cout <<c<<' ';
	return 0;
}
