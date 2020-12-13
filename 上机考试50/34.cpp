#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int i,j,k,l;
	for(i=1; i<=11; i++) {
		for(j=1; j<=4*(11-i); j++)
			cout<<" ";
		for(k=1; k<2*i-1; k+=2)
			cout<<setw(4)<<k;
		for(l=2*i-1; l>=1; l-=2)
			cout<<setw(4)<<l;
		cout<<endl;
	}
	return 0;
}
