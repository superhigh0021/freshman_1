//编程产生出1到10以内的所有数对<i,j>并输出,其中i>j
#include<iostream>
using namespace std;
int main(void)
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			if(i>j)
			printf("<%d,%d>\n",i,j);
		 } 
	}
	return 0;
}
