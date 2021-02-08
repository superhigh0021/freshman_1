#include<iostream>
#include<functional>
#include<map>
using namespace std;

template<typename MapType,
         typename KeyArgType,
         typename ValueArgType>
typename MapType::iterator efficientAddOrUpdate(MapType&m,const KeyArgType& k,const ValueArgType&v) {  //�ú����ķ�������Ϊ����������Ϊmaptype���Զ���ģ�����ʶ��������ǰ�����typename
	typename MapType::iterator lb=m.lower_bound(k);

	if(lb !=m.end() &&!(m.key_comp()(k,lb->first))) {
		lb->second=v;
		return lb;
	} else {
		typedef typename MapType::value_type MVT;
		return m.insert(lb,MVT(k,v));
	}
}

class Widget{
	public:
		Widget& operator=(double weight);
};

int main(void) {
	map<int, Widget> m;
	efficientAddOrUpdate(m,10,1.5);
	return 0;
}
