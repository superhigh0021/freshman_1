//��������m+n��Ԫ�ص���������A������m>0, n>0������Ϊ���������ص��ģ����ȷֱ�Ϊm��n���������
//д������������������εĳ���Ҫ����������A��������飬�������������м����
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
