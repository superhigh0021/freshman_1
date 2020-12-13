#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	if(n==0)
	printf("Today, I ate %d apple.",n);
	else if(n==1)
	printf("Today, I ate %d apple.",n);
	else if(n>1&&n<=100)
	printf("Today, I ate %d apples.",n);

    return 0;
}
