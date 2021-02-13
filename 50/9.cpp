//公鸡5元1只，母鸡3元1只，小鸡1元3只，花了100元钱买100只鸡
//问公鸡、母鸡、小鸡各多少只？
#include<iostream>
using namespace std;
int main(void)
{
	int x,y,z;
	for(x=0;x*5<=100;x++)
	{
		for(y=0;y*3<100;y++)
		{
			for(z=0;z/3<=100;z++)
			{
				if(x+y+z==100&&x*5+y*3+z/3==100)
				printf("有%d只公鸡，%d只母鸡,%d只小鸡\n",x,y,z);
			}
		}
	}
	return 0;
}
