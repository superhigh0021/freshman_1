#include<iostream>
using namespace std;

class Tree{
	private:
		int ages;
	public:
		Tree(int n=0)
		{
			ages = n;
		}
		void grow(int years)
		{
			ages = ages+years;
		 };
		void age()
		{
			cout<<"����Ϊ"<<ages;
		 } 
};

int main(void)
{
	Tree tree(12);
	tree.grow(4);
	tree.age();
	
	return 0;
}
