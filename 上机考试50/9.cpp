//����5Ԫ1ֻ��ĸ��3Ԫ1ֻ��С��1Ԫ3ֻ������100ԪǮ��100ֻ��
//�ʹ�����ĸ����С��������ֻ��
#include<iostream>
using namespace std;
int main(void)
{
	int x,y,z;
	for(x=0;x*5<=100;x++)
	{
		for(y=0;y*3<100;y++)
		{
			for(z=0;z/3<=100;z++)
			{
				if(x+y+z==100&&x*5+y*3+z/3==100)
				printf("��%dֻ������%dֻĸ��,%dֻС��\n",x,y,z);
			}
		}
	}
	return 0;
}
