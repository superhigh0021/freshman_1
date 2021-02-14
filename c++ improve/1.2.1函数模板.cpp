#include<iostream>
using namespace std;

template<typename T>
void Myswap(T &a,T &b) {
	T temp=a;
	a=b;
	b=temp;
}

int main(void) {
	int a=10,b=20;
	Myswap(a,b);
	cout<<a<<" "<<b<<endl;
	
	char c='c',d='d';
	Myswap<char>(c,d);
	cout<<c<<' '<<d<<endl;

	return 0;
}
