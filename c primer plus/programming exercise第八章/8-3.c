#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	int upper_num = 0;
	int lower_num = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if(islower(ch))
		   lower_num++;
		if(isupper(ch))
		   upper_num++;
	}
	
	printf("The number of lower letter is %d.\n",lower_num);
	printf("The number of upper letter is %d",upper_num);
	
	return 0;
}
