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
		printf("������NO.%d�ĳɼ�",i+1);
		cin>>grade[i];
		total+=grade[i];
	}
    average=total/N; 

	printf("ƽ����Ϊ%f",average);
	return 0;
}
