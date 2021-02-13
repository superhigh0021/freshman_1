//编程实现求解最大公约数的欧几里德算法，用户输入两个任意正整数，程序输出他们的最大公约数。算法如下：
//步骤1：	如果p < q，则交换p和q。
//步骤2：	令r是p / q 的余数。
//步骤3：	如果r = 0，则令g = q并终止；
//否则令p = q, q = r并转向步骤2
#include<iostream>
using namespace std;
void t(int p, int q)
{
	int r;
	r=p%q;
	if(r==0)
	printf("%d",q);
	else
	t(q,r);
}
void f(int p,int q)
{
	int m=p;
	int n=q;
	int g;
	if(p<q)
	{
		p=n;
		q=m;
	    t(p,q);
 	}
}
int main(void)
{
	int p,q;
	printf("请输入两个整数以求最大公约数：");
	scanf("%d %d",&p, &q);
	f(p,q);
	
	return 0;
}
