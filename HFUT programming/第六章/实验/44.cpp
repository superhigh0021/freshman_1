//������洢���ݣ�ʵ��ɸѡ���������������⡣Ҫ�����2��1000֮�������������
//ɸѡ�����2��N������������ķ����ǣ����Ƚ���Щ��ȫ������һ�������У�Ȼ���ظ�����Ĳ���ֱ������Ϊ��Ϊֹ��
//        a.�ҳ����е���С��K����Kһ����һ����������˿������
//        b.��������ɾ��K�������б�����

#include<iostream>
int DeleteNum(int *p, int n, int m);
using namespace std;

int main(void) {
	int size=998;
	int i,ch[1000];
	for(i=0; i<=998; i++)
		ch[i]=i+2;
	while(size> 0) {
		cout<<ch[0]<<endl;
		size= DeleteNum(ch,size,ch[0]);
	}
	return 0;
}
int DeleteNum(int *p, int n, int m) {
	int i,j;
	for(i=0,j=0; j<n; j++)
		if(p[j]% m)
			p[i++]= p[j];
	return i;
	









}
