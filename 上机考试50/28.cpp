//�������⣺����һ������ֵ������������֮�ͣ��������Ϊ������
//���磬6������Ϊ1��2��3����6=1+2+3����6��������������1000֮�ڵ����������������ӡ�
#include<iostream>
using namespace std;
int main(void) {
	int i,j,total;
	for(i=1; i<=1000; i++) {
		total=1;
		for(j=2; j<i; j++) {
			if((i%j)==0)
				total+=j;
		}
		if(total==i) {
			printf("%d:",i);
			for(j=2; j<i; j++) {
				if((i%j)==0)
					cout<<j<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
