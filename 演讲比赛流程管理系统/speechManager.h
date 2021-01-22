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

//设计演讲比赛管理类
class SpeechManager{
	public:
		SpeechManager();
		
		void show_Menu();
		
		void exitSystem();
		
		~SpeechManager();
		
		//初始化容器和属性
		void initSpeech();
		
		//创建12名选手
		void createSpeaker();
		
		//开始比赛   比赛流程控制
		void startSpeech();
		
		//抽签
		void speechDraw(); 
		
		//比赛
		void speechContest(); 
		
		//显示比赛结果
		void showScore(); 
		
		//保存记录
		void saveRecord(); 
		
		//读取记录
		void loadRecord();
		
		//判断文件是否为空
		bool fileIsEmpty;
		
		//往届记录
		map<int,vector<string> >m_Record; 
		
		//显示往届得分
		void showRecord(); 
		
		//清空记录
		void clearRecord(); 
		
		//成员属性
		vector<int>v1;    //第一轮选手
		
		vector<int>v2;  //第一轮晋级选手
		
		vector<int>vVictory;   //胜出前三名选手编号容器
		
		map<int,Speaker>m_Speaker;     //存放编号以及对应具体选手容器
		
		int m_Index;   //比赛轮数 
}; 

