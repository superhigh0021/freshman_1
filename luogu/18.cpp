#include<iostream>
using namespace std;

int main(void) {
	int m,a[10001],cnt;
	cin>>m;
	for(int i=1; i<=m; ++i)
		cin>>a[i];
	for(int i=1; i<m; ++i) {
		for(int j=i+1; j<=m; ++j) {
			for(int k=1; k<=m; ++k) {
				if(a[i]+a[j]==a[k])
					++cnt;
			}
		}
	}
	cout<<cnt;
	return 0;
}
