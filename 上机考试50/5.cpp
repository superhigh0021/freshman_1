//������Ķ�Ʊ��С��10��ʱ�����չ�˾����10%���ۿۣ���Ʊ�����ڻ����10����С��20��ʱ��
//���չ�˾����15%���ۿۣ���Ʊ�����ڻ����20����С��30��ʱ�����չ�˾����30%���ۿۣ�
//��Ʊ�����ڻ����30��ʱ�����չ�˾������ߵ�45%���ۿۡ�
//������붩Ʊ���������Ż�ƱƱ�ۣ���������ۿ��ʼ�Ӧ����
#include<iostream>
using namespace std;
int main(void)
{
	int price,numbers;
	
	cout<<"�����붩Ʊ������Ʊ���ۣ�";
	cin>>numbers>>price;
	
	if(numbers>0&&numbers<10)
	cout<<"�ۿ���Ϊ10%"<<"Ӧ�����Ϊ��"<<price*numbers*0.9<<endl;
	if(numbers>=10&&numbers<20)
	cout<<"�ۿ���Ϊ15%"<<"Ӧ�����Ϊ��"<<price*numbers*0.85<<endl;
	if(numbers>=20&&numbers<30)
	cout<<"�ۿ���Ϊ30%"<<"Ӧ�����Ϊ��"<<price*numbers*0.7<<endl;
	if(numbers>=30)
	cout<<"�ۿ���Ϊ45%"<<"Ӧ�����Ϊ��"<<price*numbers*0.55<<endl;
	
	return 0;
	  
}
