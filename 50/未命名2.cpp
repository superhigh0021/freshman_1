#include<iostream>
using namespace std;

class Shape{
	public:
		virtual float getarea()=0;
		virtual float getperim()=0;
};

class Circle:public Shape{
	public:
		Circle(float r):R(r){}
		float getarea(){
			return 3.14*R*R;
		}
		float getperim(){
			return 6.28*R;
		}
	private:
		float R;
};

int main(void)
{
	Shape *p;
	p=new Circle(5);
	cout<<p->getarea()<<endl;
	cout<<p->getperim()<<endl;
	
	return 0;
}
