//斐波那契（Fibonacci）数列问题：Fibonacci数列递归定义为：
//x0=0,
//x1=1,
//xi+1=xi+xi-1, i=2,3,…
//即从第二项开始，数列中的每一个元素等于前面两个元素之和
//编程输出前20项Fibonacci数。（提示可以用递归或迭代两种方式编程）
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
