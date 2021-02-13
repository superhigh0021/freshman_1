#include<bits/stdc++.h>
using namespace std;

template<class T>
void myswap(T&a,T&b) {
	T temp=a;
	a=b;
	b=temp;
}

template<class T>
void mysort(T *array,int len) {
	int max;
	for(int i=0; i<len; i++) {
		max=i;
		for(int j=i+1; j<len; j++) {
			if(array[max]<array[j])
				max=j;
		}
		myswap(array[max],array[i]);
	}
}

void test01() {
	char chararray[]="aksdujgwie";
	int num=strlen(chararray);
	mysort(chararray,num);
	cout<<chararray<<endl;
}

void test02() {
	int numarray[]= {1,8,0,3,45,27};
	int num=sizeof(numarray)/sizeof(int)-1;
	mysort(numarray,num);
	for(int i=0; i<=num; i++) {
		cout<<numarray[i]<<' ';
	}
}

int main(void) {
	test01();
	test02();

	return 0;
}
