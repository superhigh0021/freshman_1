#include<stdio.h>
int main(void)
{
	int num,m;
	printf("Please enter your favourite number:");
	scanf("%d",&num);
	m = num + 10;
	while(num<=m)
	{
		printf("%d\n",num);
	    num++;
	}
	printf("See you next time!");
	
	return 0;
}
