#include<iostream>
using namespace std;
int main(void)
{
	int x;
	cout<<"���г����Ϊ0��Ħ�г����Ϊ1��С�������Ϊ2����ͳ���𳵱��Ϊ3�����񳵱��Ϊ4"<<endl;
	cin>>x;
	switch(x)
	{
		case 0: cout<<"���";
		break;
		case 1: cout<<"2Ԫ";
		break;
		case 2: cout<<"5Ԫ";
		break;
		case 3: cout<<"8Ԫ";
		break;
		case 4: cout<<"12Ԫ";
		break;
		default:cout<<"����";
		break;
	}
	
	return 0;
 } 
