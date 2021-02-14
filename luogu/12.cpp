#include<iostream>
using namespace std;

int main(void)
{
	int ch[3];
	int i, j, k;
    for(i=0;i<3;i++)
    cin>>ch[i];
	
	for(i=0;i<2;i++)
	    for(j=0;j<2-i;j++)
	    {
	   	    if(ch[j]>ch[j+1])
	   	        {
				k=ch[j];
	   	        ch[j]=ch[j+1];
	   	        ch[j+1]=k;
	   	    }
	    }
	for(i=0;i<3;i++)
	   cout<<ch[i]<<' ';    
	return 0;
}
