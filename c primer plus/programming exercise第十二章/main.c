#include <stdio.h>
#include <stdlib.h>
void report_count();
void accumulate(int k);
int count = 0;    //�ļ��������ⲿ����

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int value;   //�Զ�����
	register int i;   //�Ĵ�������
	
	printf("Enter a positive integer (0 to quit): ");
	while (scanf("%d",&value)==1&& value > 0) 
	{
		count++;           //���ļ����������
		for(i = value; i>=0;i--)
		accumulate(i);
		printf("Enter a positive integer (0 to quit): "); 
	}
	report_count();
	
	return 0;
}

