//编写一个程序解决爱因斯坦台阶问题：
//有人走以台阶，若以每步走2级则最后剩1级；若每步走3级则最后剩2级；
//若以每步走4级则最后剩3级；若以每步走5级则最后剩4级；
//若以每步走6级则最后剩5级；若以每步走7级则最后刚好不剩。问台阶共有几级？
#include<iostream>
using namespace std;
int main(void)
{
	int i;
	for(i=7;;i++)
	{
	if(i%2==1&&i%3==2&&i%4==3&&i%5==4&&i%6==5&&i%7==0)
	break;
    }
	cout<<"有"<<i<<"级台阶";
	
	return 0;
}
