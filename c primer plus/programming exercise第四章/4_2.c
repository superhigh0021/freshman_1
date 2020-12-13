#include<stdio.h>
#include<string.h>
int main(void)

{
	char name[20];
	
	printf("Please enter your name:\n");
	scanf("%s",name);
	printf("\"%s\"\n",name);
	printf("\"%20s\"\n",name);
	printf("\"%-20s\"\n",name);
	printf("%*s",strlen(name)+3,name);
	
	return 0;
}
