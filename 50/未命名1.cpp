#include<iostream>

using namespace std;

class Shape {

public:

	Shape(){};

	~Shape(){};

	virtual float GetArea()=0;

	virtual float Getperim() = 0;

};

class Circle :public Shape {

public:

	Circle(float radius) :itsRadius(radius) {}

	~Circle(){};

	virtual float GetArea() { return 3.14 * itsRadius * itsRadius; }

	virtual float GetPerim() { return 6.28 * itsRadius; }

private:

	float itsRadius;

};

class Rectangle :public Shape {

public:

	Rectangle(float len, float width) :itsLen(len), itsWidth(width) {};

	~Rectangle(){};

	virtual float GetArea() { return itsLen * itsWidth; }

	 float Getperim() { return 2 * itsLen * itsWidth; }

	virtual float GetLen() { return itsLen; }

	virtual float GetWidth() { return itsWidth; }

private:

	float itsLen; 

	float  itsWidth;

};

int  main(void) {

	Shape* sp;

	sp = new Circle(5);

	cout << "The area of the Circle is" << sp->GetArea() << endl;

	cout << "The perimeter of the Circle is" << sp->Getperim() << endl;

	delete sp;

	sp = new Rectangle(4,6);

	cout << "The area of the Rectangle is" << sp->GetArea() << endl;

	cout << "The perimeter of the Rectanngle is" << sp->Getperim() << endl;

	delete sp;

}
