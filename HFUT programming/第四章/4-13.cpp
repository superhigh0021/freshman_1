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
	cout<<"����Բ�İ뾶";
	cin>>radius;
	Circle c(radius);
	cout<<"Բ�����Ϊ"<<c.getArea()<<endl;
	
	return 0;
}
