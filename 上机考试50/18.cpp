//��дһ����������ȫ��ͬѧĳ�ſο��Գɼ�������ƽ���ɼ����ҳ�������߷�����ͷ֡�
//��ʾ����������ͨ�������ȹ涨���������������������һ������ı�־��Ϊ���������������ݽ�����־ͳ������
#include<iostream>
using namespace std;
int main(void)
{
	int total,i,max,min;
	float ave;
    int ch[100];
    printf("������ȫ��ͬѧ�ĳɼ�(����1000��Ϊ��β)");

	for(i=0,total=0;;i++)
	{
		cin>>ch[i];
		if(ch[i]==1000)
		break;
		total+=ch[i];
		if(i==0)
		{
			max=ch[0];
			min=ch[0];
			}    
		max=max>ch[i]? max:ch[i];
		min=min<ch[i]? min:ch[i];
		  
	}
	ave=total/i;
	printf("ƽ���ɼ�Ϊ%f,��߷�Ϊ%d,��ͷ�Ϊ%d",ave,max,min);
	return 0;
   
}


