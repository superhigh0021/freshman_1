#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string currString,preString=" ",maxString;
	int currCnt=1,maxCnt=0;
	while(cin>>currString) {
		if(currString==preString) {
			++currCnt;
			if(currCnt>maxCnt) {
				maxCnt=currCnt;
				maxString=currString;

			}
		} else currCnt=1;
		preString=currString; //����preString
	}
	if(maxCnt>1)
		cout<<"���������ַ����ǣ�"<<maxString<<",�����ǣ�"<<maxCnt<<endl;
	else cout<<"ÿ���ַ�����ֻ������һ�Ρ�"<<endl;

	system("pause");
	return 0;
}
