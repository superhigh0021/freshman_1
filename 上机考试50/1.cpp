#include<iostream>
using namespace std;
int main(void)
{
	char a[21];
	char b;
	int i;
	cout<<"ÇëÊäÈë×Ö·û´®"<<endl;
	cin>>a;
	cout<<"ÇëÊäÈëÃÜÔ¿"<<endl;
	cin>>b;
	for(i=0;a[i]!=0;i++)
	{
		a[i]=a[i]^b;
        cout<<a[i];
	 }
	 
	return 0;
}
