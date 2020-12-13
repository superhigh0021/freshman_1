//38.�ú���ʵ�ֽ�һ�����ַ�����ʽ��ʾ��ʮ��������ת��Ϊһ��ʮ�������������磬���롱A2��ת��Ϊ162��
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
bool rightFormat(string);
int convert(string);
int change2num(char);
int main() {
	string hex;
	cout<<"����һ��ʮ������������ĸ�ô�д��"<<endl;
l:
	cin>>hex;
	if(!rightFormat(hex)) {
		cout<<"������ȷ��ʮ�������������������룺";
		goto l;
	}
	cout<<"����ǣ�"<<convert(hex)<<endl;
}

bool rightFormat(string s) {
	bool b = true;
	for(int i=0; i<s.size(); i++) {
		if(s[i]<'0' ||(s[i]>'9' && s[i]<'A') || s[i]>'F') {
			b = false;
			break;
		}
	}
	return b;
}

int convert(string s) {
	int dec = 0;
	for(int i=0; i<s.size(); i++) {
		dec = dec +change2num(s[i])*pow(16,(s.size()-1-i));
	}
	return dec;
}

int change2num(char c) {
	switch(c) {
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		default:
			return 0;
	}
}
