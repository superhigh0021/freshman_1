#include<iostream>
using namespace std;

class shape {
	public:
		~shape() {
			cout<<"已调用"<<endl;
		}
};

int main(void) {
	shape s;
	cout<<"不好意思，我先"<<endl;
	return 0;
}
