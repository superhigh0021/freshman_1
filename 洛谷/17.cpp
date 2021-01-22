#include<iostream>
using namespace std;

int main(void) {
	int a[10001];
	int n,m,min=10000,cnt=0;
	cin>>n>>m;
	for(int i=0; i<n; ++i) {
		cin>>a[i];
	}
	for(int i=0; i<=n-m; ++i) {
		for(int j=i; j<i+m; ++j) {
			cnt+=a[j];
		}
		if(min>cnt)
			min=cnt;
		cnt=0;
	}
	cout<<min<<endl;

	return 0;
}
