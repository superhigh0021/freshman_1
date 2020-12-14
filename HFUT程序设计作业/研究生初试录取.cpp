#include<bits/stdc++.h>
using namespace std;

class candidate {
		friend class scoreline;
	private:
		string name;   //考生姓名
		string number;   //准考证号
		string professional;   //考生专业
		string isgraduate;    //是否应届生
		int po_score,m_score,e_score,p_score,all;
	public:
		int getall() {
			return all;
		}
		void print();
		void input1(string name,string number,string professional,string isgraduate,int po_score,int m_score,int e_score,int p_score);
		void zero();
		void format();
};

void candidate::print() {
	printf("考生姓名：%s  准考证号：%s  考生专业：%s  是否应届生：%s  政治分数：%d  数学成绩：%d  英语成绩：%d  专业成绩：%d  总分：%d",
	       name.c_str(),number.c_str(),professional.c_str(),isgraduate.c_str(),po_score,m_score,e_score,p_score,all);
}

void candidate::input1(string name,string number,string professional,string isgraduate,int po_score,int m_score,int e_score,int p_score) {
	this->name=name;
	this->number=number;
	this->professional=professional;
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

void input2(int po_line,int m_line,int e_line,int p_line,int all_line) {
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
	cout<<setw(6)<<policital<<setw(5)<<math<<setw(5)<<english<<setw(5)<<majorclass<<setw(6)<<all<<setw(3)<<endl;
}

bool cmp(candidate a,candidate b){
	return a.getall()>b.getall();
}

int main(void){
	string name,number,professional,isgraduate;
	int po_score,m_score,e_score,p_score,all;
	freopen()
}


























