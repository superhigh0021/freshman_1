#include<iostream>
using namespace std;

void convert(int a[][3],int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			int t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	}
}

int main(void) {
	int a[3][3] {1,2,3,4,5,6,7,8,9};
	convert(a,3);
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
