#include<iostream>
using namespace std;

class Rectangle{
	private:
		int x,y,a,b;
	public:
		int s;
		void area(int X,int Y, int A, int B);
		
};

void Rectangle::area(int X,int Y,int A,int B)
{
	x=X;
	y=Y;
	a=A;
	b=B;
	s=(a-x)*(b-y);
}

int main(void)
{
	int x,y,a,b;
	Rectangle r;
	printf("������ε����½����꣺");
	cin>>x>>y;
	printf("������ε����Ͻ����꣺");
	cin>>a>>b;
	r.area(x,y,a,b);
    cout<<"���ε����Ϊ��"<<r.s<<endl;
	
	return 0; 
}
