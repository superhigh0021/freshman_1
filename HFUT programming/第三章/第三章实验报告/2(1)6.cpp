#include<iostream>
#include<math.h>
using namespace std;
int main(void)
{
	float a,b,value;
	cout<<"����������������ֵ"<<endl;
	cin>>a>>b;
	value = fabs(pow(a,2)-pow(b,2))+floor(a-b);
	cout<<value<<endl;
	
	return 0;
}
