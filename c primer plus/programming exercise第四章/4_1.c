#include<stdio.h>
int main(void)
{
	char fname[10];
	char lname[10];
	printf("Please enter your name:");
	scanf("%s %s", fname,lname);
	printf("%s %s",lname,fname);
	
	return 0;
	
 } 
