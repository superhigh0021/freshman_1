#include<stdio.h>
int main(void)
{
	int x,y;
	
	printf("Enter your age: ");
	scanf("%d",&x);
	y = x * 3.156e7;
	printf("You have come to the world for %d seconds!",y);
	
	return 0;
}
