#include<iostream>
using namespace std;
int main(void) {
	int m, n, i, j, num;
	int k = 0;
	printf("请输入两个整数m,n");
	cin >> m >> n;
	for (i = m; i < n; i++) {
		num = 1;
		for (j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				num = 0;
				break;
			}
		}
		if (num) {
			printf("%6d ", i);
			k++;
			if (k % 8 == 0)
				printf("\n");
		}
	}
	return 0;
}
