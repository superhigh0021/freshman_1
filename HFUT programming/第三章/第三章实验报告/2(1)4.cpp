#include<iostream>
#include<math.h>
#define e 2.71
using namespace std;
int main(void)
{
	float x,y,value;
	cout<<"������x,y����ֵ"<<endl;
	cin>>x>>y;
	value = pow(e,x+y)+pow(e,x-y);
	cout<<value<<endl;
	
	return 0;
}
