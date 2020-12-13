//给定含有m+n个元素的整型数组A（其中m>0, n>0）它分为两个互不重叠的，长度分别为m和n的子数组段
//写出交换这两个子数组段的程序，要求不引入数组A以外的数组，但可引入若干中间变量
#include<iostream>
using namespace std;
#define MAX 100

int main(void) {
	int a[MAX],m,n,i,j,t;
	cin>>m>>n;
	for (i=0; i<m+n; i++)
		cin>>a[i];
	for(i=m-1; i>=0; i--) {
		t=a[i];
		for(j=0; j<n; j++)      
		    a[i+j]=a[i+j+1];
		a[i+n]=t;
	}
	for(i=0; i<m+n; i++)   cout<<a[i]<<' ';
	cout<<endl;
}
