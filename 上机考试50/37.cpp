//��дһ���ݹ麯������һ������ת��Ϊ��Ӧ���ַ��������������ԭ�Ϳ�����Ϊ��void int2str(int number)��
#include <iostream>
using namespace std;
void int2str ( int number ) {
	int a ;
	
    if(number!=0){
    	a=number%10;
    	int2str(number/10);
    	cout<< char(a+48)<<' ';
	}
}
int main (void) {
	int num;
	cout<< "Input a number:" ;
	cin>> num ;
	if(num<0) {
		num=-num;
		cout<<'-'<<' ';
	}
	int2str( num ) ;
	cout<< endl ;
}
