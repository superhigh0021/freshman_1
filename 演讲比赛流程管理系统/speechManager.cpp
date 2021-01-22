#include"speechManager.h"

SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
}

void SpeechManager::show_Menu() {
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem() {
	cout<<"��ӭ�´�ʹ�ã�"<<endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech() {
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index=1;
}

void SpeechManager::createSpeaker() {
	string nameSeed="ABCDEFGHIJKL";
	for(int i=0; i<nameSeed.size(); ++i) {
		string name="ѡ��";
		name+=nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name=name;

		for(auto &j:sp.m_Score)
			j=0;

		//����ѡ�ֱ��  ���ҷ��뵽v1������
		this->v1.push_back(i+10001);

		//ѡ�ֵı���Լ���Ӧѡ�֣�����map����
		this->m_Speaker.insert(make_pair(i+10001, sp));
	}
}

void SpeechManager::startSpeech() {

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();
}

//��ǩ
void SpeechManager::speechDraw() {
	cout<<"��"<<this->m_Index<<"��ѡ�����ڳ�ǩ"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"��ǩ���ݽ�˳�����£�"<<endl;

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

//����
void SpeechManager::speechContest() {
	cout<<"��"<<this->m_Index<<"�ֱ�����ʽ��ʼ"<<endl;
	vector<int>v_Src;   //����ѡ�ֵ�����
	if(this->m_Index==1) {
		v_Src=v1;
	} else {
		v_Src=v2;
	}
	//��������ѡ�ֽ��б���
	for(auto it:v_Src) {
		//��ί���
		deque<double>d;
		for(int i=0; i<10; ++i) {
			double score=(rand()%401+600)/10.f;
			//cout<<std::left<<setw(4)<<score<<' ';
			d.push_back(score);
		}
		cout<<endl;
		sort(d.begin(),d.end(),greater<double>());  //��������
		d.pop_back();
		d.pop_front();   //ȥ����߷ֺ���ͷ�
		double sum=accumulate(d.begin(),d.end(),0.0f);
		double avg=sum/(double)d.size();
		
		//��ƽ���ַ��뵽map������
		this->m_Speaker[it].m_Score[this->m_Index-1] = avg;
	}
}

SpeechManager::~SpeechManager() {

}

































