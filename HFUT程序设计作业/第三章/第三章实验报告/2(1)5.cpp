#include<iostream>
#include<math.h>
using namespace std;
int main(void)
{
	int m, x;
	float value;
	cout<<"������һ��������ֵ"<<endl;
	cin>>x;
	m = 1 + sqrt(1 + pow(x,2));
	value = log10(m);
	cout<<value<<endl;
	
	return 0;
}
