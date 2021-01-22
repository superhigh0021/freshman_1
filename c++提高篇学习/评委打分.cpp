#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

/*��5����ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣�ȡƽ����*/
class Person{
	public:
		Person(string name,int score){
			this->m_Name=name;
			this->m_Score=score;
		}
		string m_Name;
		int m_Score;
};

void createPerson(vector<Person>&v){
	string nameSeed="ABCDE";
	for(int i=0;i<5;++i){
		string name = "ѡ��";
		name+=nameSeed[i];
		
		int score=0;
		Person p(name,score);
		v.push_back(p);   //�������Ķ������������ 
	}
}

void setScore(vector<Person>&v){
	for(auto it = v.begin();it!=v.end();++it){
		//����ί�ķ������뵽deque������
		deque<int>d;
		for(int i=0;i<10;++i){
			int score=rand() % 41 + 60;
			d.push_back(score); 
		} 
		//������
		sort(d.begin(),d.end());
		//ȥ����ߺ���ͷ�
		d.pop_back();
		d.pop_front();
		//ȡƽ����
		int sum=0;
		for(auto dit=d.begin();dit!=d.end();++dit){
			sum+=*dit;
		} 
		int avg=sum/d.size();
		
		//��ƽ���ָ�ֵ��ѡ��
		it->m_Score=avg; 
	}
}

void showScore(vector<Person>&v){
	for(auto it=v.begin();it!=v.end();++it){
		cout<<"������"<<it->m_Name<<" ƽ���֣�"<<it->m_Score<<endl;
	}
}

int main(void){
	vector<Person>v;  //���ѡ�ֵ����� 
	createPerson(v);
	setScore(v);
	showScore(v);
	
	system("pause");
	return 0;
}
