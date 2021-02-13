#include<iostream>
using namespace std;

class Cat{
	public: 
	    static int numOfCats;
	    static void getNumOfCats(){
	    	cout<<numOfCats<<endl;
		}
};

int Cat::numOfCats=14;

int main(void){
	Cat::getNumOfCats();
	
	return 0;
}
