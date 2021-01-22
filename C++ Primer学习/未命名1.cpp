#include <iostream>
#include <memory>

using namespace std;

class A {
	public:
		A() {
			cout << "A Constructor" << endl;
		}
		~A() {
			cout << "A Destruct" << endl;
		}
};

void fun(shared_ptr<A>p) {
	cout<<"fun count:"<<p.use_count()<<endl;
}

int main() {
	shared_ptr<A> p = make_shared<A>();
	cout << "count:"<<p.use_count() << endl;
	fun(p);
	cout << "count:"<<p.use_count() << endl;
	return 0;
}
