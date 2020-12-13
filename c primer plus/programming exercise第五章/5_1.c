#include<stdio.h>
#define M 60
int main(void)
{
	int min,minutes,hour;
	
	printf("Please enter time in minute:\n");
	scanf("%d",&minutes);
	
	while(minutes >=0)
	{
		hour = minutes / M;
	    min = minutes % M;
		printf("%d minutes is %d hour %d minutes.\n",minutes,hour,min);
		printf("Please enter another time(<=0 to quit)");
		scanf("%d",&minutes);
	}
	printf("See you next time!");
	return 0;
	
}
