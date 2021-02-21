#include <iostream>
#include"speechManager.h"
#include<string>
#include<ctime>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	//���һ�����������
	srand((unsigned int)time(NULL)); 
	SpeechManager sm;	
	
	int choice =0;   //���ڴ洢�û�����
	
	while(true){
		sm.show_Menu();
		cout<<"���������ѡ��"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				sm.startSpeech();
				break;
			case 2:
				sm.showRecord();
				break;
			case 3:
				sm.clearRecord();
				break;
			case 0:
				sm.exitSystem();
				break;
			default:
				system("cls");
				break;
		}
	}
	
	system("pause");
	return 0;
}
