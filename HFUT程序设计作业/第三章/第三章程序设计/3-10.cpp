#include<iostream>
using namespace std;
void han(int x, int y);
void shu(int x, int y);

int main(void)
{
	int x,y,t;
	cout<<"������������"<<endl;
	cin>>x>>y;
	han(x,y);
	shu(x,y);
	
	return 0;
}

void han(int x, int y)
{
	int m,n,p;
	if(x>=y)
	  m = x;
	else
	  m = y;
	for(n=m;n>=1;n--)
	    if(x%n==0 && y%n==0)
	    {
	    	p=n;
	    	break;
		}
	cout<<x<<","<<y<<"�����Լ��Ϊ"<<p<<endl;
}

void shu(int x, int y)
{
	int m,n,p,k;
	if(x>=y)
	  m = x, k = y;
	else
	  m = y, k = x;
	for(n=m;n>=1;n--)
	    if(x%n==0 && y%n==0)
	    {
	    	p=n;
	    	break;
		}
	cout<<x<<","<<y<<"����С������Ϊ"<<p*k<<endl;
}
