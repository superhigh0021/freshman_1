//编程求出1000以内的所有符合如下条件的数：
//其高位数字小于低位数字。如12，238等。但21，548不符合条件。
#include<iostream>
using namespace std;
int main(void)
{
	int i,x,y,a,b,c;
	for(i=10;i<1000;i++)
	{
		if(i<100)
		{
			x=i/10;
			y=i%10;
			if(x<y)
			printf("%d ",i);
		}
		else
		{
			a=i/100;
			b=i/10%10;
			c=i%10;
			if(a<b&&b<c)
			printf("%d ",i);
		}
	}
	return 0;
 } 
