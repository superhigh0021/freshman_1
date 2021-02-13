#include<iostream>
using namespace std;
float num(float x,float a,float b,float c,float d)
{
	float sum;
	sum = x+(a+b)/(c-d);
	return sum;
}

int main(void)
{
	float x,a,b,c,d,sum;
	cout<<"ÇëÊäÈëx£¬a£¬b£¬c£¬d"<<endl;
	cin>>x>>a>>b>>c>>d;
	sum = num(x,a,b,c,d);
	cout<<sum<<endl;
	
	return 0;
}
