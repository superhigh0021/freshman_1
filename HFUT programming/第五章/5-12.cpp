#include<iostream>
using namespace std;
int fnl(){
	static int n=0;
	n++;
	return n;	
}
int main(void)
{
	int i,x;
	for(i=0;i<=9;i++)
	x=fnl();
	printf("x=%d",x);

	return 0;
}
