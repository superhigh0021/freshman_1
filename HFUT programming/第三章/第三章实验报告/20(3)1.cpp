#include<iostream>
#include<math.h>
using namespace std;
void num(float a, float b, float c)
{
	float m,value1,value2;
	m = b*b - 4*a*c;
	if(m>0)
	{
	    value1 =(-b+sqrt(m))/(2*a);
	    value2 =(-b-sqrt(m))/(2*a);
	    cout<<"方程的解为"<<value1<<"和"<<value2<<endl;
    }
    else if(m==0)
    {
    	value1=-b/2*a;
	    cout<<"方程的解为"<<value1<<endl;
	}
	else
	    cout<<"方程无解"<<endl; 
}
int main(void)
{
	int a,b,c;
	cout<<"请输入方程的三个系数"<<endl; 
	cin>>a>>b>>c;
	num(a,b,c);
	
	return 0;
}
