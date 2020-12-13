//一位顾客在购物时，如果买4个苹果剩下4角钱．如果买5个苹果则缺5角钱
//请问，该顾客带了多少钱？多少钱可以买一个苹果？
#include<iostream>
using namespace std;
int main(void)
{
	int price,money;
		for(price=1;;price++)
		{
			if(4*price+4==5*price-5)
		    {
		    	printf("苹果单价为%d角\n",price);
		    	break;
			}
			
		}
		printf("该顾客带了%d角\n",4*price+4);

	return 0;
}
