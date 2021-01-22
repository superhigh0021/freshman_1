#include"speechManager.h"

SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
}

void SpeechManager::show_Menu() {
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem() {
	cout<<"欢迎下次使用！"<<endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech() {
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index=1;
}

void SpeechManager::createSpeaker() {
	string nameSeed="ABCDEFGHIJKL";
	for(int i=0; i<nameSeed.size(); ++i) {
		string name="选手";
		name+=nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_Name=name;

		for(auto &j:sp.m_Score)
			j=0;

		//创建选手编号  并且放入到v1容器中
		this->v1.push_back(i+10001);

		//选手的编号以及对应选手，放入map容器
		this->m_Speaker.insert(make_pair(i+10001, sp));
	}
}

void SpeechManager::startSpeech() {

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();
}

//抽签
void SpeechManager::speechDraw() {
	cout<<"第"<<this->m_Index<<"轮选手正在抽签"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"抽签后演讲顺序如下："<<endl;

	if(this->m_Index==1) {
		random_shuffle(v1.begin(),v1.end());
		for(auto i:v1)
			cout<<i<<' ';
		cout<<endl;
	} else {
		random_shuffle(v2.begin(),v2.end());
		for(auto i:v2)
			cout<<i<<' ';
		cout<<endl;
	}
	cout<<"------------------------"<<endl;
	system("pause");
	cout<<endl;
}

//比赛
void SpeechManager::speechContest() {
	cout<<"第"<<this->m_Index<<"轮比赛正式开始"<<endl;
	vector<int>v_Src;   //比赛选手的容器
	if(this->m_Index==1) {
		v_Src=v1;
	} else {
		v_Src=v2;
	}
	//遍历所有选手进行比赛
	for(auto it:v_Src) {
		//评委打分
		deque<double>d;
		for(int i=0; i<10; ++i) {
			double score=(rand()%401+600)/10.f;
			//cout<<std::left<<setw(4)<<score<<' ';
			d.push_back(score);
		}
		cout<<endl;
		sort(d.begin(),d.end(),greater<double>());  //降序排列
		d.pop_back();
		d.pop_front();   //去除最高分和最低分
		double sum=accumulate(d.begin(),d.end(),0.0f);
		double avg=sum/(double)d.size();
		
		//将平均分放入到map容器中
		this->m_Speaker[it].m_Score[this->m_Index-1] = avg;
	}
}

SpeechManager::~SpeechManager() {

}

































