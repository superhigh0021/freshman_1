#include <stdio.h>
#include <stdlib.h>
void report_count();
void accumulate(int k);
int count = 0;    //文件作用域，外部链接

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int value;   //自动变量
	register int i;   //寄存器变量
	
	printf("Enter a positive integer (0 to quit): ");
	while (scanf("%d",&value)==1&& value > 0) 
	{
		count++;           //该文件作用域变量
		for(i = value; i>=0;i--)
		accumulate(i);
		printf("Enter a positive integer (0 to quit): "); 
	}
	report_count();
	
	return 0;
}

