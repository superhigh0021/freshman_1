#include<iostream>
using namespace std;

int main(void) {
	int x,d,a1,a2,a3,a4;
//	a1=x;
//	a2=x+d;
//	a3=x+2*d;
//	a4=x+3*d;
	for(x=-100; x<100; x++) {
		for(d=0; d<100; d++) {
			a1=x;
			a2=x+d;
			a3=x+2*d;
			a4=x+3*d;
			if((a1+a2+a3+a4)==26&&a1*a2*a3*a4==880) {
				cout<<x<<' '<<d<<'\n';
				break;
			}
		}
	}
	return 0;
}
