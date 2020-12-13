#include<iostream>
using namespace std;
int main() {
	char a[6]="ABCDE",i,j,x;
	for(i=0; i<=4; i++) {
		for(j=i; j<=4; j++)
			cout<<a[j]<<" ";
		for(x=0; x<i; x++)
			cout<<a[x]<<" ";
		cout<<endl;
	}
	return 0;
}
