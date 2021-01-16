#include<iostream>
using namespace std;
void convert_number(int number ,int radius);

int main(void) {
	int number,radius;
	cout<<"Please input a number:"<<endl;
	cin>>number;
	cout<<"Please input a radius:"<<endl;
	cin>>radius;
	cout<<"The result is ";
	convert_number(number, radius);

	return 0;
}

void convert_number(int number, int radius) {
	int a[20];
	for(int i=19; i>=0; --i) {
		a[i]=number%radius;
		number/=radius;
	}
	for(int i=0; i<20; ++i) {
		while(a[i]!=0) {
			for(int j=i; j<20; ++j)
				cout<<a[j];
			break;
		}
	}
}
