#include<iostream>
using namespace std;

class Rectangle{
	private:
		int length,width;
	
	public:
		int square;
		void area(int L,int W);
};

void Rectangle::area(int L,int W) 
{
	length = L;
	width = W;
	square = length*width;
}

int main(void)
{
	int L,W; 
	Rectangle r; 
	printf("请输入矩形的长和宽：");
	cin>>L>>W;
	r.area(L,W);
	cout<<"矩形的面积为："<<r.square<<endl;
	
	return 0;
}
