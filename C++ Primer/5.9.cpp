#include<iostream>
using namespace std;

int main(void) {
	char ch;
	int aCnt=0,oCnt=0,eCnt=0,iCnt=0,uCnt=0;
	cout<<"������һ���ı�"<<endl;
	while(cin>>ch) {
		switch(ch) {
		case 'a':
			aCnt++;
			break;
		case 'o':
			oCnt++;
			break;
		case 'e':
			eCnt++;
			break;
		case 'i':
			iCnt++;
			break;
		case 'u':
			uCnt++;
			break;
		default:
			break;
		}
	}
	cout<<aCnt<<' '<<oCnt<<' '<<eCnt<<' '<<iCnt<<' '<<uCnt<<endl;
	
	return 0;
}
