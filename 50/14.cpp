//���ʵ��������Լ����ŷ������㷨���û�������������������������������ǵ����Լ�����㷨���£�
//����1��	���p < q���򽻻�p��q��
//����2��	��r��p / q ��������
//����3��	���r = 0������g = q����ֹ��
//������p = q, q = r��ת����2
#include<iostream>
using namespace std;
void t(int p, int q)
{
	int r;
	r=p%q;
	if(r==0)
	printf("%d",q);
	else
	t(q,r);
}
void f(int p,int q)
{
	int m=p;
	int n=q;
	int g;
	if(p<q)
	{
		p=n;
		q=m;
	    t(p,q);
 	}
}
int main(void)
{
	int p,q;
	printf("���������������������Լ����");
	scanf("%d %d",&p, &q);
	f(p,q);
	
	return 0;
}
