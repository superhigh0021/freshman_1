#include<iostream>
using namespace std;

class Shape {
	public:
		virtual float getArea() {
			return -1;
		}
};

class Circle:public Shape {
	public:
		Circle(float radius):itsRadius(radius) {}
		float getArea() {
			return 3.14*itsRadius*itsRadius;
		}
	private:
		float itsRadius;
};

class Rectangle:public Shape {
	public:
		Rectangle(float len, float width):itsLength(len),itsWidth(width) {}
		virtual float getArea() {
			return itsLength * itsWidth;
		}
	private:
		float itsLength;
		float itsWidth;
};

class Square:public Rectangle {
	public:
		Square(float a): Rectangle(a,a) {}
};

int main(void) {
	Rectangle A(3,5);
	cout<<A.getArea()<<endl;
	Circle B(6);
	cout<<B.getArea()<<endl;
	Square C(7);
	cout<<C.getArea();

	return 0;
}
