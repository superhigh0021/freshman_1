//现在有 t 毫升肥宅快乐水，要均分给 n 名同学。每名同学需要 2 个杯子。现在想知道每名同学可以获得多少毫升饮料（严格精确到小数点后 3 位）
//以及一共需要多少个杯子。输入一个实数 t 和一个整数 n，使用空格隔开。输出两个数字表示答案，使用换行隔开。
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
	float t, n;
	scanf("%f %f",&t, &n);
	printf("%.3f\n%d",t/n, 2*(int)n);
	
	return 0;
}
