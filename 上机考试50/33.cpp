//쳲�������Fibonacci���������⣺Fibonacci���еݹ鶨��Ϊ��
//x0=0,
//x1=1,
//xi+1=xi+xi-1, i=2,3,��
//���ӵڶ��ʼ�������е�ÿһ��Ԫ�ص���ǰ������Ԫ��֮��
//������ǰ20��Fibonacci��������ʾ�����õݹ��������ַ�ʽ��̣�
#include<iostream>
using namespace std;
int f(int i) {
	int r;
	if(i==0)
		r=0;
	else if(i==1)
		r=1;
	else
		r=f(i-1)+f(i-2);

	return r;

}
int main(void) {
	int i;
	for(i=0; i<=20; i++) {
		cout<<f(i)<<' ';
	}
	return 0;
}
