#include<iostream>
using namespace std;
int main(void)
{
	int year,month;
	cout<<"请输入年份";
	cin>>year;
	cout<<"请输入月份";
	cin>>month;
	
	if(month ==1||month==3||month==5||month==7||month==8||month==10||month==12)
	    cout<<"该年该月有31天"<<endl;
	else if(month ==4||month==6||month==9||month==11)
	    cout<<"该年该月有30天"<<endl;
	else if((year%4==0&&year%100!=0)||year%400==0)
	    cout<<"该年该月有29天"<<endl;
	else
	    cout<<"该年该月有28天"<<endl;
	
	system("pause");
	return 0;
	    
}
