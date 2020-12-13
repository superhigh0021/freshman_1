//求一整数的等差数列，该数列满足下述条件：头4项数的和值为26，积值为880。
//（提示：该数列公差为正整数，否则数列将出现负数；该数列的首项必须小于5，且其公差也小于5，否则头四项数的和将大于26。）
#include<iostream>
using namespace std;
int main(void)
{
	int k,d,a1,a2,a3,a4;
	for(k=1;;k++)
	{
		for(d=0;d<k;d++)
		{
			a1=k-d;
			a2=2*k-d;
			a3=3*k-d;
			a4=4*k-d;
			if((a1+a2+a3+a4)==26&&(a1*a2*a3*a4)==880)
			{
				printf("数列为%dn-%d",k,d);
				break;
			}
		}
	}
	return 0;
 } 
