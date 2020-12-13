//£Ó£½£±¡Á£²£«£³¡Á£´£«£µ¡Á£¶£«¡­£«£³£¹¡Á£´£°
#include<iostream>
using namespace std;
int main(void)
{
	int sum=0,i,x=0;

	for(i=1;i<=39;i+=2)
	{
		x=i*(i+1);
		sum+=x;
	}
	printf("%d",sum);
	
	return 0;
}
