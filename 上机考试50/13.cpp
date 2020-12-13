//编写程序打印乘法口诀表
#include<iostream>
using namespace std;
int main(void)
{
	int m,n;
	int k =0;
	for(m=1;m<=9;m++)
	{
		for(n=1;n<=9;n++)
		    {
			printf("%d*%d=%2d ",m,n,m*n);
			k++;
			if(k%9==0)
			printf("\n");
		     } 
	}
	return 0;
}
