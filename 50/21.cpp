#include<iostream>
using namespace std;
int main(void)
{
	int i;
	double b=1,sum=0;
	for(i=1;b>=1e-8;i++)
	{
		sum+=b;
		b/=i;
	}
	printf("e=%lf",sum);
	return 0;
}
