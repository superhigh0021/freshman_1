#include<iostream>
#include <math.h>
using namespace std;
int main (void)
{
	int x,y,t;
	float z;
	float e= 2.71;
	cout<<"请输入两个数x，y："<<endl;
	cin>>x;
	cin>>y;
	
	if(x<0 && y<0)
	   z = pow(e,x+y);
	else if((x+y)>=1 &&(x+y) <10)
	   z = log (x+y);
	else
	{
		t = abs(x+y);
		z = log10(t+1);
	}
	
	cout<<z<<endl;
	
	return 0;
	   
}
