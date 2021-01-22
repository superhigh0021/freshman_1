#include<iostream>
#include<memory>
using namespace std;

int main(void) {
	auto e1=make_shared<int>(100);
	cout<<e1.use_count()<<endl;
	weak_ptr<int>e2=e1;
	cout<<e1.use_count()<<endl;
	if(shared_ptr<int>e3=e2.lock()){
		cout<<*e3;
		
	}
//		auto e3=move(e2);
//		cout<<e1.use_count()<<endl;
	return 0;
}
