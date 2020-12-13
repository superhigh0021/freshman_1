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
	printf("输入矩形的左下角坐标：");
	cin>>x>>y;
	printf("输入矩形的右上角坐标：");
	cin>>a>>b;
	r.area(x,y,a,b);
    cout<<"矩形的面积为："<<r.s<<endl;
	
	return 0; 
}
