#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
void num(int a, int b, int c)
{
	float  value1, value2;
	int m;
	m = b * b - 4 * a * c;
	if (m > 0)
	{
		value1 = (-b + sqrt(m)) / (2 * a);
		value2 = (-b - sqrt(m)) / (2 * a);
		printf("����%dx^2+%dx+%d=0�Ľ�Ϊ:%f,%f", a, b, c, value1, value2);
	}
	else if (m == 0)
	{
		value1 = -b / 2 * a;
		printf("����%dx^2+%dx+%d=0�Ľ�Ϊ:%f", a, b, c, value1);
	}
	else
		printf("����%dx^2+%dx+%d=0�޽�", a, b, c);
}
int main(void)
{
	int a, b, c;
	cout << "�����뷽�̵�����ϵ��" << endl;
    scanf("%d %d %d",&a,&b,&c);	
	num(a, b, c);

	return 0;
}
