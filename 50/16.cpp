//有关专家十分关注珠江渔业资源的问题。目前珠江中大约有8000万条鱼，平均每年以3.5%的速度减少。
//请编写一个程序，计算在多少年之后鱼的数目下降到目前的一半？多少年后下降到目前的十分之一？
//（提示注意整数类型的取值范围）。
#include<iostream>
using namespace std;
int main(void)
{
	int i;
	double m;
	for(i=0,m=8000;i<29;i++,m*=0.965)
	{
		if(m<=4000)
		{
			printf("一半要%d年\n",i);
			break;
		}
    }
		for(i=0,m=8000;;i++,m*=0.965)
		{
		    if(m<=800)
		    {
			    printf("十分之一要%d年",i);
			    break;
		    }
	    }
	return 0;
	
}
