#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

/*有5吗名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分和最低分，取平均分*/
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
		string name = "选手";
		name+=nameSeed[i];
		
		int score=0;
		Person p(name,score);
		v.push_back(p);   //将创建的对象放入容器中 
	}
}

void setScore(vector<Person>&v){
	for(auto it = v.begin();it!=v.end();++it){
		//将评委的分数放入到deque容器中
		deque<int>d;
		for(int i=0;i<10;++i){
			int score=rand() % 41 + 60;
			d.push_back(score); 
		} 
		//先排序
		sort(d.begin(),d.end());
		//去除最高和最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum=0;
		for(auto dit=d.begin();dit!=d.end();++dit){
			sum+=*dit;
		} 
		int avg=sum/d.size();
		
		//将平均分赋值给选手
		it->m_Score=avg; 
	}
}

void showScore(vector<Person>&v){
	for(auto it=v.begin();it!=v.end();++it){
		cout<<"姓名："<<it->m_Name<<" 平均分："<<it->m_Score<<endl;
	}
}

int main(void){
	vector<Person>v;  //存放选手的容器 
	createPerson(v);
	setScore(v);
	showScore(v);
	
	system("pause");
	return 0;
}
