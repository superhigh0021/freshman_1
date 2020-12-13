//用数组存储数据，实现筛选法求素数问题的求解。要求求出2到1000之间的所有素数。
//筛选法求出2～N间的所有素数的方法是：首先将这些数全部放入一个数组中，然后重复下面的操作直到数组为空为止：
//        a.找出其中的最小数K，则K一定是一个素数，因此可输出。
//        b.从数组中删除K及其所有倍数。

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
