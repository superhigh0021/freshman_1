#include<iostream>
#include<math.h>
using namespace std;
int main(void)
{
	float x,sum;
	cout<<"请输入一个数以求值"<<endl;
	cin>>x;
	sum = sin(x) + cos(x) +atan(x);
	cout<<sum<<endl;
	
	return 0;
}
