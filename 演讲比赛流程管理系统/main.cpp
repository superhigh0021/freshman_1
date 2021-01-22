#include <iostream>
#include"speechManager.h"
#include<string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	SpeechManager sm;	
	
	int choice =0;   //用于存储用户输入
	
	while(true){
		sm.show_Menu();
		cout<<"请输入你的选择："<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				sm.startSpeech();
				break;
			case 2:
				break;
			case 3:
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
