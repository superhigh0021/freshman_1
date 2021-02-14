#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main(void)
{
	float m,h,n;
	cin>>m>>h;
	n=m/(h*h);
	if(m>=40&&m<=120&&h>=1.4&&h<=2.0)
	{
		if(n<18.5)
		cout<<"Underweight"<<endl;
		else if(n>=18.5&&n<24)
		cout<<"Normal"<<endl;
		else if(n>=24)
		cout<<n<<'\n'<<"Overweight"<<endl;
	}
	
	return 0;
}
