#include <iostream>
#include <string.h>
#include<stdio.h>
using namespace std;
int stre ( char[] ) ;

int main() {
	char str [10] , *p = str ;

	gets (p) ;
	cout << stre (p) << endl ;
}

int stre (char *str) {
	int num = 0 ;
	while(  *( str + num ) != '\0' )  
	num ++ ;
	return num;
}
