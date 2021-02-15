#include <iostream>
using namespace std;

typedef int Rank;          //?
#define DEFAULT_CAPACITY 3 //??????

template <typename T>
class Vector {
	protected:
		Rank _size;
		int _capacity;
		T *_elem;                                    //?????????
		void copyFrom(T const *A, Rank lo, Rank hi); //??????A[lo,hi)
		void expand();                               //???????
		void shrink();                               //?????????
		bool bubble(Rank lo, Rank hi);               //????
		void bubbleSort(Rank lo, Rank hi);           //??????
		Rank max(Rank lo, Rank hi);                  //??????
		void selectionSort(Rank lo, Rank hi);        //??????
		void merge(Rank lo, Rank hi);                //????
		void mergeSort(Rank lo, Rank hi);            //??????
		Rank partition(Rank lo, Rank hi);            //??????
		void quickSort(Rank lo, Rank hi);            //??????
		void heapSort(Rank lo, Rank hi);             //???
	public:
		//????
		Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
			_elem = new T[_capacity = c];
			for (_size = 0; _size < s; _elem[_size++] = v)
				;
		} //???c????s????????v
		Vector(T const *A, Rank n) {
			copyFrom(A, 0, n);
		} //??????
		Vector(T const *A, Rank lo, Rank hi) {
			copyFrom(A, lo, hi);
		} //??
		Vector(Vector<T> const &V) {
			copyFrom(V._elem, 0, V._size);
		} //??????
		Vector(Vector<T> const &V, Rank lo, Rank hi) {
			copyFrom(V._elem, lo, hi);
		} //??
		//????
		~Vector() {
			delete[] _elem;
		}
		//??????
		Rank size() const {
			return _size;
		} //??
		bool empty() const {
			return !_size;
		}                       //??
		int disordered() const; //????????????
		Rank find(T const &e) const {
			return find(e, 0, _size);
		}                                              //????????
		Rank find(T const &e, Rank lo, Rank hi) const; //????????
		Rank search(T const &e) const {                //????????
			return (0 >= _size) ? -1 : search(e, 0, _size);
		}
		Rank search(T const &e, Rank lo, Rank hi) const;     //????????
		// ??????
		T &operator[](Rank r);                               //???????,??????????????
		const T &operator[](Rank r) const;                   //???????????
		Vector<T> &operator=(Vector<T> const &);             //???????,????????
		T remove(Rank r);                                    //????r???
		int remove(Rank lo, Rank hi);                        //??????[lo, hi)?????
		Rank insert(Rank r, T const &e);                     //????
		Rank insert(T const &e) {
			return insert(_size, e);    //?????????
		}
		void sort(Rank lo, Rank hi);                         //?[lo, hi)??
		void sort() {
			sort(0, _size);    //????
		}
		void unsort(Rank lo, Rank hi);                       //?[lo, hi)??
		void unsort() {
			unsort(0, _size);    //????
		}
		int deduplicate();                                   //????
		int uniquify();                                      //????
		// ??
		void traverse(void (*)(T &));                        //??(??????,????????)
		template <typename VST>
		void traverse(VST &); //??(??????,??????)
};

template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0; //???? ????
	while (lo < hi) {
		_elem[size++] = A[lo++];
	}
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V) {
	if (_elem)
		delete[] _elem;
	copyFrom(V._elem, 0, V.size());
	return *this;
}

template <typename T>
void Vector<T>::expand() {
	if (_size < _capacity)
		return;
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;
	T *oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; ++i)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template <typename T>
void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1)
		return;
	if (_size << 2 > _capacity)
		return;
	T *oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; ++i)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template <typename T>
T &Vector<T>::operator[](Rank r) {
	return _elem[r];
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {
	T *V = _elem + lo;
	for (Rank i = hi - lo; i > 0; --i)
		std::swap(V[i - 1], V[rand() % i]);
}

template <typename T>
static bool lt(T *a, T *b) {
	return lt(*a, *b);
}

template <typename T>
static bool lt(const T &a, const T &b) {
	return a < b;
}

template <typename T>
static bool eq(T *a, T *b) {
	return eq(*a, *b);
}

template <typename T>
static bool eq(const T &a, const T &b) {
	return a == b;
}

template <typename T> //?????????:????????e???;???,??lo-1
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]))
		return hi; //?hi<lo ?????? ??hi???????
}

template <typename T>
Rank Vector<T>::insert(Rank r, const T &e) {
	this->expand();
	for (int i = _size; i > r; --i)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;
	_size++;

	return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi)
		return 0;
	while (hi < _size)
		_elem[lo++] = _elem[hi++]; //??,?????
	_size = lo;
	this->shrink();
	return hi - lo; //??????????
}

template <typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	this->remove(r, r + 1);
	return e; //???????
}

template <typename T> //???
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
		this->find(_elem[i], 0, i) < 0 ? i++ : this->remove(i);
	return oldSize - _size;
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit) {
	for (int i = 0; i < _size; ++i)
		visit(_elem[i]); //????????,??
}

template<typename T>
struct Increase {
	void operator()(T& e) {
		++e;
	}
};

template<typename T>
void increase(Vector<T>& V) {
	V.traverse(Increase<T>());
}

template<typename T>
struct Decrease {
	void operator()(T& e) {
		--e;
	}
};

template<typename T>
void decrease(Vector<T>& V) {
	V.traverse(Decrease<T>());
}



void test01() {
	Vector<int> s;
	for(int i=0; i!=10; ++i) {
		s.insert(0,i);
	}
	for(int i=0; i!=10; ++i) {
		cout<<s[i]<<' ';
	}
	cout<<endl;
	increase(s);
	for(int i=0; i!=10; ++i) {
		cout<<s[i]<<' ';
	}
}

int main(void) {
	test01();

	system("pause");
	return 0;
}
