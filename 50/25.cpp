#include<stdio.h>
#include<stdlib.h>
 
int reverse( int number )
{
	int a,sum=0;
	while(number)
	{
		a=number%10;  //核心三行代码
		sum=sum*10+a;
		number/=10;
	}
	return sum;	
}
 
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", reverse(n));
    return 0;
}
