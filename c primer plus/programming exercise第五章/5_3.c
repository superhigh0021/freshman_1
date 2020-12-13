#include<stdio.h>
#define dpw 7
int main(void)
{
	int days,Day,Week;
	printf("Enter your days:");
	scanf("%d",&days);
	
	while(days>0)
	{
		Week = days / dpw;
		Day = days % dpw;
		printf("%d days are %d weeks, %d days\n",days,Week,Day);
		printf("Enter another days(<=0 to quit)");
		scanf("%d",&days);
	}
	printf("See you next time!");
	
	return 0;
	
}
