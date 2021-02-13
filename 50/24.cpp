#include<iostream>
#include<math.h>
using namespace std;
int main(void)
{
	int x,i;
	double m,n=0;
	cout<<"请输入一个数";
	cin>>x;
	m=x;
	for(i=1;fabs(m)>=1e-6;i+=2)
	{
		n+=m;
		m=m*(-x*x)/((i+1)*(i+2));
	}
	printf("%f",n);
	
	return 0;
}
