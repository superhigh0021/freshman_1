//完数问题：若有一数，其值等于它的因子之和，则该数称为完数。
//例如，6的因子为1、2、3，而6=1+2+3，故6是完数。编程输出1000之内的所有完数及其因子。
#include<iostream>
using namespace std;
int main(void) {
	int i,j,total;
	for(i=1; i<=1000; i++) {
		total=1;
		for(j=2; j<i; j++) {
			if((i%j)==0)
				total+=j;
		}
		if(total==i) {
			printf("%d:",i);
			for(j=2; j<i; j++) {
				if((i%j)==0)
					cout<<j<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
