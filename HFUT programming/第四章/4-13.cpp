#include<iostream>
using namespace std;

class Circle{
	private:
		float radius;
	
	public:
		Circle(float r)
		{
		    radius = r;
		}
		float getArea()
		{
			return 3.14*radius*radius;
		}
};

int main(void)
{
	float radius;
	cout<<"输入圆的半径";
	cin>>radius;
	Circle c(radius);
	cout<<"圆的面积为"<<c.getArea()<<endl;
	
	return 0;
}
