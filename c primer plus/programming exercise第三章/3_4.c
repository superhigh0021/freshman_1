#include<stdio.h>
int main(void)
{
	float x;
	printf("Enter a floating-point value: ");
	scanf("%f",&x);
	printf("fixed-point notation: %f\n",x);
	printf("exponential notation: %e\n",x);
	printf("p notation: %a\n",x);
	
	return 0;
 } 
