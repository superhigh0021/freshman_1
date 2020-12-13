#include<iostream>
#include<stdio.h>
using namespace std;
int main(void)
{
	int a,b,c,d,e,f;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(b>d)
	{
		f=d+60-b;
		e=c-1-a;
	}
	else
	{
		f=d-b;
		e=c-a;
	}
	printf("%d %d", e, f);
	
	return 0;
}
