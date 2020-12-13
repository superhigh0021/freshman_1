#include<iostream>
using namespace std;

class BaseClass {
	public:
		void fn1() {
			cout<<"fn1(),yes!"<<endl;
		}
		void fn2() {
			cout<<"fn2(),yes!"<<endl;
		}
};

class DerivedClass:public BaseClass {
	public:
		void fn1() {
			cout<<"fn1(),yes!"<<endl;
		}
		void fn2() {
			cout<<"fn2(),yes!"<<endl;
		}
};

int main(void) {
	DerivedClass b;

	BaseClass *k;
	k=&b;

	DerivedClass *d;
    d=&b;

	b.fn1();
	b.fn2();

	k->fn1();
	k->fn2();

	d->fn1();
	d->fn2();

	return 0;
}
