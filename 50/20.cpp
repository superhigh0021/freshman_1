//把一张1元钞票换成1分、2分和5分的硬币，每种至少有1枚，问有多少种换法？
#include<iostream>
using namespace std;
int main(void)
{
	int x,y,z;
	int num=0;
	for(x=1;x<=100;x++)
	{
		for(y=1;y<=50;y++)
		{
			for(z=1;z<=20;z++)
			{
				if((x+2*y+5*z)==100)
				num++;
			}
		}
	}
	printf("有%d种换法",num);
	return 0;
}
