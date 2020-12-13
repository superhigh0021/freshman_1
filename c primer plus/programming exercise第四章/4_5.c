#include<stdio.h>
int main(void)
{
	float speed,size;
	
	printf("Please enter the size of a file in megabytes:\n");
	scanf("%f",&size);
	printf("please enter the speed of downloading per second in megabits:\n");
	scanf("%f",&speed);
	
	printf("At %.2f megabits per second,a file of %.2f megabytes\ndownloads in %.2f seconds",
	speed,size,size/speed);
	
	return 0;
	
}
