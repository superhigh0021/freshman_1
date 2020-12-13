#include<iostream>
using namespace std;

class Complex{
	private:
		float A;
		int B;
	public:
		Complex(float a,int b=0){
		A=a;
		B=b;
		};
		void add(Complex&p);
		void show();
};

void Complex::add(Complex&p)
{
	A+=p.A;
	B+=p.B;
 } 
 
void Complex::show()
{
	printf("%.1f+%di",A,B);
}

int main(void)
{
	Complex c1(3,5);
	Complex c2=4.5;
	c1.add(c2);
	c1.show();
	
	return 0;
}
