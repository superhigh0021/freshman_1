// wheat.c -- ָ������
#include<stdio.h>
#define SQUARE 64          //�����еķ�����
int main(void)
{
	const double CROP = 2e16;      //����С�����������
	double current, total;
	int count = 1;
	
	printf("square     grains     total     ");
	printf("fraction of\n");
	printf("           added      grains     ");
	printf("world total\n");
	total=current=1.0;      //�ӵ�һ�Ź�����ʼ
	printf("%4d  %13.2e  %12.2e  %12.2e\n", count, current,total, total / CROP);
	while (count < SQUARE)
	{
		count= count + 1;
		current = 2.0 * current;
		total = total + current;
		printf("%4d %13.2e %12.2e %12.2e\n", count , current, total, total/ CROP);
	 } 
	 printf("That's all.\n");
	 
	 return 0;
 } 
