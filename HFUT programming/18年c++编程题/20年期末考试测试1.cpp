#include<iostream>
using namespace std;

class shape {
	public:
		~shape() {
			cout<<"�ѵ���"<<endl;
		}
};

int main(void) {
	shape s;
	cout<<"������˼������"<<endl;
	return 0;
}
