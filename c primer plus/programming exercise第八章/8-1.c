#include<stdio.h>
int main(void)
{
	char ch;
	int num = 0;
	
	while ((ch = getchar()) != EOF)
	{
		num++;
	}
	printf("����%d���ַ�\n",num);
	
	return 0;
}
