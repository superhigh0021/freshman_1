#include  <iostream>
#include  <iomanip>
using   namespace  std;
static   int  is_circle_num( int  number, int  radius);
int  main() {
	int num,max_num;

	cout<<"Please input an interger (for example 1200) :";
	cin>>max_num;
	for(num=0; num<max_num; num++) {
		if (is_circle_num(num,10)==1&&is_circle_num(num,2)==1) {
			cout<<setw(6)<<num;
			cout<<" is a circle number in decimal and binary system! ";
		}
	}
	return 0;
}

int  is_circle_num( int  number, int  radius) {
	int left_num,right_num;
	int max_power,left_power,right_power;

	max_power=1;
	while(0 != (left_power = (max_power == 1 ? (number/radius) : (left_power / radius)))) {
		max_power*=radius;
	}
	left_power=max_power;
	right_power=radius;

	while(left_power >= right_power) {
		right_num = (number % right_power) *radius / right_power;
		left_num= (number / left_power) % radius;

		if(right_num!=left_num)
			return 0;
		right_power*=radius;
		left_power/=radius;
	}
	return 1;
}
