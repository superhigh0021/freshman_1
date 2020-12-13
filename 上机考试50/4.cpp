#include<iostream>
using namespace std;
int main(void)
{
	int score;
	cout<<"ÇëÊäÈë¿¼ÊÔ³É¼¨";
	cin>>score;
	if(score>=90&&score<=100)
	    cout<<"Excellent";
    else if(score>=80)
	    cout<<"Very good";
	else if(score>=70)
	    cout<<"Good";
	else if(score>=60)
	    cout<<"Pass";
    else
	    cout<<"No Pass";
	
	return 0; 
}
