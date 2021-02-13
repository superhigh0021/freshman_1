#include<iostream>
using namespace std;
int main(void)
{
	int x;
	cout<<"自行车编号为0，摩托车编号为1，小汽车编号为2，大客车与火车编号为3，货柜车编号为4"<<endl;
	cin>>x;
	switch(x)
	{
		case 0: cout<<"免费";
		break;
		case 1: cout<<"2元";
		break;
		case 2: cout<<"5元";
		break;
		case 3: cout<<"8元";
		break;
		case 4: cout<<"12元";
		break;
		default:cout<<"错误！";
		break;
	}
	
	return 0;
 } 
