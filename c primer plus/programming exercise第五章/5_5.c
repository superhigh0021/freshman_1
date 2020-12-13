#include<stdio.h>
int main(void)
{
	int count, sum,days;
	printf("Enter your working days:");
	scanf("%d",&days);
	
	count = 1;
	sum = 0;
	while(count <= days)
	{
	    sum = sum + count;
	printf("sum = %d\n", sum);
	count++;
     }
     return 0;
}
