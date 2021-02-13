//旅行社的订票量小于10张时，航空公司给予10%的折扣；订票量大于或等于10张且小于20张时，
//航空公司给予15%的折扣；订票量大于或等于20张且小于30张时，航空公司给予30%的折扣；
//订票量大于或等于30张时，航空公司给予最高的45%的折扣。
//编程输入订票张数及单张机票票价，程序输出折扣率及应付款额。
#include<iostream>
using namespace std;
int main(void)
{
	int price,numbers;
	
	cout<<"请输入订票量及机票单价：";
	cin>>numbers>>price;
	
	if(numbers>0&&numbers<10)
	cout<<"折扣率为10%"<<"应付款额为："<<price*numbers*0.9<<endl;
	if(numbers>=10&&numbers<20)
	cout<<"折扣率为15%"<<"应付款额为："<<price*numbers*0.85<<endl;
	if(numbers>=20&&numbers<30)
	cout<<"折扣率为30%"<<"应付款额为："<<price*numbers*0.7<<endl;
	if(numbers>=30)
	cout<<"折扣率为45%"<<"应付款额为："<<price*numbers*0.55<<endl;
	
	return 0;
	  
}
