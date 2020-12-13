#include<stdio.h>
void cube(double n);
int main(void)
{
	double n;
	printf("Please enter a type of double number:");
	scanf("%lf",&n);
	cube(n);
	return 0;
}

void cube (double n)
{
	double cubed;
	cubed = n * n * n;
	printf("The value of %lf is %lf",n,cubed);
}
