//һλ�˿��ڹ���ʱ�������4��ƻ��ʣ��4��Ǯ�������5��ƻ����ȱ5��Ǯ
//���ʣ��ù˿ʹ��˶���Ǯ������Ǯ������һ��ƻ����
#include<iostream>
using namespace std;
int main(void)
{
	int price,money;
		for(price=1;;price++)
		{
			if(4*price+4==5*price-5)
		    {
		    	printf("ƻ������Ϊ%d��\n",price);
		    	break;
			}
			
		}
		printf("�ù˿ʹ���%d��\n",4*price+4);

	return 0;
}
