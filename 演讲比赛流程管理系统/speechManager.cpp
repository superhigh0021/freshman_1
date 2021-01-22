#include"speechManager.h"

SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
	//���������¼
	this->loadRecord();
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

	//����¼������Ҳ���
	this->m_Record.clear();
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
//��һ�ֱ���
	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();

	//3�����������ʾ
	this->showScore();

//�ڶ��ֱ���
	++this->m_Index;

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();

	//3�����������ʾ
	this->showScore();

	//4������������ļ���
	this->saveRecord();

	//���ñ���
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout<<"����������"<<endl;
	system("pause");
	system("cls");
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

	//׼��һ����ʱ����  ���С��ɼ�
	multimap<double,int,greater<double>>groupScore;
	int num=0;  //��¼��Ա����  6��һ��

	vector<int>v_Src;   //����ѡ�ֵ�����
	if(this->m_Index==1) {
		v_Src=v1;
	} else {
		v_Src=v2;
	}
	//��������ѡ�ֽ��б���
	for(auto it:v_Src) {
		++num;
		//��ί���
		deque<double>d;
		for(int i=0; i<10; ++i) {
			double score=(rand()%401+600)/10.f;
			//cout<<std::left<<setw(4)<<score<<' ';
			d.push_back(score);
		}
		sort(d.begin(),d.end(),greater<double>());  //��������
		d.pop_back();
		d.pop_front();   //ȥ����߷ֺ���ͷ�
		double sum=accumulate(d.begin(),d.end(),0.0f);
		double avg=sum/(double)d.size();

		//��ƽ���ַ��뵽map������
		this->m_Speaker[it].m_Score[this->m_Index-1] = avg;

		//���������  ������ʱС��������
		groupScore.insert(make_pair(avg,it));   //key�ǵ÷֣�value�Ǿ�����
		//ÿ����ȡ��ǰ����
		if(num%6 == 0) {
			cout<<"��"<<num/6<<"С��������Σ�"<<endl;
			for(auto i:groupScore) {
				cout<<"��ţ�"<<i.second<<' '<<"������"<<this->m_Speaker[i.second].m_Name
				    <<' '<<"�ɼ���"<<this->m_Speaker[i.second].m_Score[this->m_Index-1];
				cout<<endl;
			}

			//ȡ��ǰ����
			int cnt=0;    //������
			for(auto j:groupScore) {
				if(this->m_Index==1) {
					v2.push_back(j.second);
				} else {
					vVictory.push_back(j.second);
				}
				if(++cnt==3)
					break;
			}

			groupScore.clear();     //С���������
		}
	}

	cout<<"��"<<this->m_Index<<"�ֱ������"<<endl;
	system("pause");
}

//��ʾ�������
void SpeechManager::showScore() {
	cout<<"��"<<this->m_Index<<"�ֽ���ѡ����Ϣ���£�"<<endl;

	vector<int>v;
	if(this->m_Index==1)
		v=v2;
	else
		v=vVictory;
	for(auto it:v) {
		cout<<"ѡ�ֱ�ţ�"<<it<<"������"<<this->m_Speaker[it].m_Name
		    <<"�÷֣�"<<this->m_Speaker[it].m_Score[this->m_Index-1]<<endl;
	}
	cout<<endl;

	system("pause");
	system("cls");
}

//�����¼
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv",ios::out | ios::app);  //��׷�ӵķ�ʽд�ļ�

	//��ÿ���˵����� д�뵽�ļ���
	for(auto it : vVictory) {
		ofs<<it<<","<<this->m_Speaker[it].m_Score[1]<<",";
	}
	ofs<<endl;

	ofs.close();
	cout<<"��¼�ѱ���"<<endl;

	this->fileIsEmpty=false;
}

//��ȡ��¼
void SpeechManager::loadRecord() {
	ifstream ifs;
	ifs.open("speech.csv",ios::in);

	if(!ifs.is_open()) {
		this->fileIsEmpty=true;
		ifs.close();
		return;
	}

	//�ļ�������
	char ch;
	ifs>>ch;
	if(ifs.eof()) {
		this->fileIsEmpty=true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty=false;
	ifs.putback(ch);   //�������ȡ�ĵ����ַ�  �Ż���
	string data;
	int index=0;
	while(ifs>>data) {

		vector<string>v;   //���

		int pos=-1;    //�鵽��������λ��
		int start=0;
		while(true) {
			pos=data.find(",",start);
			if(pos==-1) {
				break;
			}
			string temp=data.substr(start,pos-start);
			v.push_back(temp);
			start=pos+1;
		}
		this->m_Record.insert(make_pair(index,v));
		++index;
	}
	ifs.close();
}

//�����¼
void SpeechManager::showRecord() {
	if(this->fileIsEmpty) {
		cout<<"�ļ�Ϊ�ջ��ļ������ڣ�"<<endl;
	} else {
		for(auto i=0; i<this->m_Record.size(); ++i) {
			cout<<"��"<<i+1<<"��"
			    <<"�ھ���ţ�"<<this->m_Record[i][0]<<"�÷�"<<this->m_Record[i][1]<<' '
			    <<"�Ǿ���ţ�"<<this->m_Record[i][2]<<"�÷�"<<this->m_Record[i][3]<<' '
			    <<"������ţ�"<<this->m_Record[i][4]<<"�÷�"<<this->m_Record[i][5]<<' '<<endl;
		}
	}
	system("pause");
	system("cls");
}

//��ռ�¼
void SpeechManager::clearRecord() {
	ofstream ofs;
	ofs.open("speech.csv",ios::trunc);
	ofs.close();
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout<<"��ճɹ�"<<endl;

	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager() {}
