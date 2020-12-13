#include<stdio.h>
int main(void)
{
	char ch;
	int num = 0;
	
	while ((ch = getchar()) != EOF)
	{
		num++;
	}
	printf("¹²ÓÐ%d¸ö×Ö·û\n",num);
	
	return 0;
}
