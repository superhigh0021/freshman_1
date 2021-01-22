#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

//����ݽ�����������
class SpeechManager{
	public:
		SpeechManager();
		
		void show_Menu();
		
		void exitSystem();
		
		~SpeechManager();
		
		//��ʼ������������
		void initSpeech();
		
		//����12��ѡ��
		void createSpeaker();
		
		//��ʼ����   �������̿���
		void startSpeech();
		
		//��ǩ
		void speechDraw(); 
		
		//����
		void speechContest(); 
		
		//��ʾ�������
		void showScore(); 
		
		//�����¼
		void saveRecord(); 
		
		//��ȡ��¼
		void loadRecord();
		
		//�ж��ļ��Ƿ�Ϊ��
		bool fileIsEmpty;
		
		//�����¼
		map<int,vector<string> >m_Record; 
		
		//��ʾ����÷�
		void showRecord(); 
		
		//��ռ�¼
		void clearRecord(); 
		
		//��Ա����
		vector<int>v1;    //��һ��ѡ��
		
		vector<int>v2;  //��һ�ֽ���ѡ��
		
		vector<int>vVictory;   //ʤ��ǰ����ѡ�ֱ������
		
		map<int,Speaker>m_Speaker;     //��ű���Լ���Ӧ����ѡ������
		
		int m_Index;   //�������� 
}; 

