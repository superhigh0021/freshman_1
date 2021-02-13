//26.水仙花数问题：水仙花数是一种三位数，它的值等于每个数字的立方和。
//例如，153=13+53+33。编程输出小于999的水仙花数。
#include<iostream>
using namespace std;
int main(void)
{
	int i,a,b,c;
	for(i=100;i<=999;i++)
	{
		a=i%10;
		b=i/10%10;
		c=i/100;
		if(i==a*a*a+b*b*b+c*c*c)
		printf("%d ",i);
	}
	return 0;
}
