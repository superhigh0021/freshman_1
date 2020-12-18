#include<iostream>
using namespace std;
int z=3;

void f(int &x, int y,int& z) {
	x=x+y;
	y=x*z;
	z++;
	cout<<x<<'\t'<<y<<'\t'<<z<<endl;
}

int main() {
	int x,y,z;
	x=1;
	y=3;
	z=2;
	f(x,y,z);
	cout<<x<<'\t'<<y<<'\t'<<z<<'\t'<<::z<<endl;
	f(y,z,x);
	cout<<x<<'\t'<<y<<'\t'<<z<<'\t'<<::z<<endl;
	f(z,x,y);
	cout<<x<<'\t'<<y<<'\t'<<z<<'\t'<<::z<<endl;
}
