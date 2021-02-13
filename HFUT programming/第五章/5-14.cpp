#include<iostream>
using namespace std;
class Car;
class Boat{
	friend int getTotalWeight(Boat &A,Car &B);
	public:
		int weight;
		Boat(int n){
			weight = n;
		}
};
class Car{
	friend int getTotalWeight(Boat &A,Car &B);
	public:
		int weight;
		Car(int n){
			weight = n;
		}
	
};

int getTotalWeight(Boat &A,Car &B){
	int total;
	total =A.weight + B.weight;
	return total;	
}

int main(void)
{
	Boat A(123);
	Car B(234);
	cout<<getTotalWeight(A,B)<<endl;
    
    return 0;
}
