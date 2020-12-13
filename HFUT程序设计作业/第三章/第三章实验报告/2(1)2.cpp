#include<iostream>
#include<math.h>
using namespace std;
float num(float x)
{
	float m,n,p;
	m = 1/(x+1);
	n = 1 + 1/(x+m);
	p = sqrt(n);
	return p;
}

int main(void)
{
	float x,sum;
	cout<<"请输入一个数以计算"<<endl;
    cin>>x;
    sum = num(x);
    cout<<sum<<endl;
    
    return 0;
}
