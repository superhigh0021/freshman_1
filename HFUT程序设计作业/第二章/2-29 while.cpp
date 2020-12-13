#include<iostream>
using namespace std;
int main(void)
{
	int i;
	int n=2;
	int num;
	while(n<=100)
	{
		num = 1;
		i =2;
		while(i*i <=n)
		{
			if(n%i == 0)
			{ 
			   num = 0;
			   break;
			}
			i++;
		}
		if(num)
		  cout<<n<<"ÊÇÖÊÊý"<<endl;
		n++;
	}
	
	return 0;
	
}
