#include<iostream>
using namespace std;
#define N 8

int main(void){
    int grade[N];
	int i;
	float total=0;
	float average;
	for(i=0;i<N;i++)
	{
		printf("请输入NO.%d的成绩",i+1);
		cin>>grade[i];
		total+=grade[i];
	}
    average=total/N; 

	printf("平均分为%f",average);
	return 0;
}
