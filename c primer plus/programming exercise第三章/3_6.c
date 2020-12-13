#include<stdio.h>
int main(void)
{
	float x,y;
	printf("The weight of water is ");
	scanf("%f",&x);
	y=x*950/3.0e-23;
	printf("The number of watermolecule is %e.\n",y);
	
	return 0;
}
