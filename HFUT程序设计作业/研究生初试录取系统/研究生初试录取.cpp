#include<bits/stdc++.h>
using namespace std;

class candidate {
		friend class scoreline;
	private:
		string name;   //考生姓名
		string number;   //准考证号
		string profession;   //考生专业
		string isgraduate;    //是否应届生
		int po_score,m_score,e_score,p_score,all;
	public:
		int getall() {
			return all;
		}
		void print();
		void input1(string name,string number,string profession,string isgraduate,int po_score,int m_score,int e_score,int p_score);
		void zero();
		void format();
};

void candidate::print() {
	cout<<"考生姓名"<<name<<"准考证号"<<number<<"报考专业"<<profession<<"是否为应届生"<<isgraduate<<"政治"<<po_score<<"数学"<<m_score<<"英语"<<e_score<<"专业课"<<m_score<<"总分"<<all<<endl;
}

void candidate::input1(string name,string number,string profession,string isgraduate,int po_score,int m_score,int e_score,int p_score) {
	this->name=name;
	this->number=number;
	this->profession=profession;
	this->isgraduate=isgraduate;
	this->po_score=po_score;
	this->m_score=m_score;
	this->e_score=e_score;
	this->p_score=p_score;
	this->all=po_score+m_score+e_score+p_score;
}

class scoreline {
	private:
		int po_line,m_line,e_line,p_line,all_line;
	public:
		int judge(candidate a);
		void input2(int po_line,int m_line,int e_line,int p_line,int all_line);
};

int scoreline::judge(candidate a) {
	if(a.all>=all_line&&a.po_score>=po_line&&a.m_score>=m_line&&a.e_score>=e_line&&a.p_score>=p_line)
		return 1;
	return 0;
}

void scoreline::input2(int po_line,int m_line,int e_line,int p_line,int all_line) {
	this->po_line=po_line;
	this->m_line=m_line;
	this->e_line =e_line;
	this->p_line=p_line;
	this->all_line=all_line;
}

void candidate::zero() {        //将该考生成绩置零
	this->po_score=0;
	this->m_score=0;
	this->e_score=0;
	this->p_score=0;
	this->all=0;
}

void candidate::format() {
	cout<<name<<setw(14)<<number<<setw(12)<<profession<<setw(12)<<isgraduate;
	cout<<setw(6)<<po_score<<setw(5)<<m_score<<setw(5)<<e_score<<setw(5)<<m_score<<setw(6)<<all<<setw(3)<<endl;
}

bool cmp(candidate a,candidate b) {
	return a.getall()>b.getall();
}

int main(void) {
	string name,number,profession,isgraduate;
	int person,i,po_score,m_score,e_score,p_score,all,right=0;
	char testfile1[100],testfile2[100];
	candidate* c;
	cout<<"输入总共有多少学生待处理：";
	cin>>person;
	c=new candidate[person];
	freopen("in.txt","r",stdin);
	for(i=0; i<person; i++) {
		cin>>name>>number>>profession>>isgraduate>>po_score>>m_score>>e_score>>p_score;
		c[i].input1(name,number,profession,isgraduate,po_score,m_score,e_score,p_score);
	}

	int po_line,m_line,e_line,p_line,all_line;
	printf("请输入政治，数学，外语，专业基础课程的分数线:\n");
	freopen("CON","r",stdin);
	cin.clear();
	cin>>po_line>>m_line>>e_line>>p_line>>all_line;
	scoreline s;
	s.input2(po_line, m_line, e_line, p_line, all_line);
	for(i=0; i<person; i++) {
		if(s.judge(c[i]))
			right++;
		else c[i].zero();
	}
	sort(c,c+person,cmp);
	printf("共有%d个学生通过初试\n",right);
	cout<<"考生姓名"<<"  准考证号     "<<"报考专业"<<"  是否为应届生"<<" 政治"<<" 数学"<<" 英语"<<" 专业课"<<" 总分"<<endl;
	for(i=0; i<=right-1; i++)
		c[i].format();
	freopen("out.txt","w",stdout);
	printf("共有%d个学生通过初试\n",right);
	cout<<"考生姓名"<<"  准考证号     "<<"报考专业"<<"  是否为应届生"<<" 政治"<<" 数学"<<" 英语"<<" 专业课"<<" 总分"<<endl;
	for(i=0; i<=right-1; i++)
		c[i].format();
	return 0;
}
