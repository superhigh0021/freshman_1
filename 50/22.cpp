#include<iostream>
using namespace std;
int main(void)
{
	int i,sum=0,b=1;
	for(i=2;i<=8;i++)
	{
		sum+=b;
		b*=i;
	}
	printf("%d",sum);
	
	return 0;
}
