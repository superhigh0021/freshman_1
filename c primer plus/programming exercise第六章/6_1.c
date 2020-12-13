#include<stdio.h>
#define SIZE 26
int main(void)
{
	char lowercase[26];
	int i;
	
	for(i = 0;i<= SIZE;i++)
	   lowercase[i] = 'a' + i;
	printf("The array contents:");
	for(i = 0;i< SIZE;i++)
	   printf("%c",lowercase[i]);
	
	return 0;
 }
