#include<iostream>
using namespace std;
int main(void)
{
	int year,month;
	cout<<"���������";
	cin>>year;
	cout<<"�������·�";
	cin>>month;
	
	if(month ==1||month==3||month==5||month==7||month==8||month==10||month==12)
	    cout<<"���������31��"<<endl;
	else if(month ==4||month==6||month==9||month==11)
	    cout<<"���������30��"<<endl;
	else if((year%4==0&&year%100!=0)||year%400==0)
	    cout<<"���������29��"<<endl;
	else
	    cout<<"���������28��"<<endl;
	
	system("pause");
	return 0;
	    
}
