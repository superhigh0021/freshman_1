#include <iostream>
#include <algorithm>
#include "vector.h"
using namespace std;

typedef int Rank;          //��
#define DEFAULT_CAPACITY 3 //Ĭ�ϳ�ʼ����

template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0; //����ռ� ��ģ����
    while (lo < hi)
    {
        _elem[size++] = A[lo++];
    }
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &V)
{
    if (_elem)
        delete[] _elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
}

template <typename T>
void Vector<T>::expand()
{
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
void Vector<T>::shrink()
{
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
T &Vector<T>::operator[](Rank r)
{
    return _elem[r];
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T *V = _elem + lo;
    for (Rank i = hi - lo; i > 0; --i)
        std::swap(V[i - 1], V[rand() % i]);
}

template <typename T>
static bool lt(T *a, T *b)
{
    return lt(*a, *b);
}

template <typename T>
bool lt(const T &a, const T &b)
{
    return a < b;
}

template <typename T>
static bool eq(T *a, T *b)
{
    return eq(*a, *b);
}

template <typename T>
static bool eq(const T &a, const T &b)
{
    return a == b;
}

template <typename T> //����������˳����ң��������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo-1
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const
{
    while ((lo < hi--) && (e != _elem[hi]))
        return hi; //��hi<lo ����ζ��ʧ�� ����hi������Ԫ�ص���
}

template <typename T>
Rank Vector<T>::insert(Rank r, const T &e)
{
    this->expand();
    for (int i = _size; i > r; --i)
        _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;

    return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    while (hi < _size)
        _elem[lo++] = _elem[hi++]; //���ţ�ƿ���˹
    _size = lo;
    this->shrink();
    return hi - lo; //���ر�ɾ��Ԫ�ص���Ŀ
}

template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    this->remove(r, r + 1);
    return e; //���ر�ɾ��Ԫ��
}

template <typename T> //�ܳ
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    Rank i = 1;
    while (i < _size)
        this->find(_elem[i], 0, i) < 0 ? i++ : this->remove(i);
    return oldSize - _size;
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (int i = 0; i < _size; ++i)
        visit(_elem[i]); //������������ʵ�֣��
}

struct Increase
{
    template <typename T>
    void operator()(T &e)
    {
        ++e;
    }
};

template <typename T>
void increase(Vector<T> &V)
{
    Increase i;
    V.traverse(i);
}

struct Decrease
{
    template <typename T>
    void operator()(T &e)
    {
        --e;
    }
};

template <typename T>
void decrease(Vector<T> &V)
{
    Decrease d;
    V.traverse(d);
}

template <typename T>
int Vector<T>::disordered()const
{ //������������������Ԫ�ضԵ�����
    int n = 0;
    for (int i = 1; i < _size; ++i)
    {
        if (_elem[i - 1] > _elem[i])
            ++n;
    }
    return n;
}

template <typename T>
int Vector<T>::uniquify()
{
    Rank i = 0, j = 0;
    while (++j < _size)
    {
        if (_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    }
    _size = ++i;
    this->shrink();

    return j - i;
}

template <typename T>
static Rank binSearch(T *A, const T &e, Rank lo, Rank hi)
{
    while (lo < hi)
    {
        Rank mi = (lo + hi) >> 1;
        if (e < A[mi])
            hi = mi;
        else if (A[mi] < e)
            lo = mi + 1;
        else
            return mi;
    }
    return -1;
}

class Fib
{ //Fibonacci������
private:
    int f, g; //f = fib(k - 1), g = fib(k)����Ϊint�ͣ��ܿ�ͻ���ֵ���
public:
    Fib(int n) //��ʼ��Ϊ��С��n����СFibonacci��
    {
        f = 1;
        g = 0;
        while (g < n)
            next();
    }                       //fib(-1), fib(0)��O(log_phi(n))ʱ��
    int get() { return g; } //��ȡ��ǰFibonacci�O(1)ʱ��
    int next()
    {
        g += f;
        f = g - f;
        return g;
    } //ת����һFibonacci�O(1)ʱ��
    int prev()
    {
        f = g - f;
        g -= f;
        return g;
    } //ת����һFibonacci�O(1)ʱ��
};

template <typename T>
static Rank fibSearch(T *A, const T &e, Rank lo, Rank hi)
{
    Fib fib(hi - lo);
    while (lo < hi)
    {
        while (hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        if (e < A[mi])
            hi = mi;
        else if (A[mi] < e)
            lo = mi + 1;
        else
            return mi;
    }
}

template <typename T>
Rank Vector<T>::search(const T &e, Rank lo, Rank hi) const
{
    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi)
{
    switch (rand() % 2)
    {
    case 1:
        bubbleSort(lo, hi);
        break;
    case 2:
        mergeSort(lo, hi);
        ;
        break;
    // case 3:
    //     selectionSort(lo, hi);
    //     break;
    // case 4:
    //     heapSort(lo, hi);
    //     break;
    default:
        // quickSort(lo, hi);
        break;
    }
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
    while (!bubble(lo, hi))
        ;
}

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)
{
    bool sorted = true;
    while (++lo < hi)
    {
        if (_elem[lo - 1] > _elem[lo])
        {
            sorted = false;
            swap(_elem[lo - 1], _elem[lo]);
        }
    }
    return sorted;
}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi)
{
    if (hi - lo < 2)
        return;
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
    T *A = _elem + lo;
    int lb = mi - lo;
    T *B = new T[lb];
    for (Rank i = 0; i < lb; ++i)
        B[i] = A[i];
    int lc = hi - mi;
    T *C = _elem + mi;
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
    {
        if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
            A[i++] = B[j++];
        if ((k < lc) && (!(j < lb) || (C[k] < B[j])))
            A[i++] = C[k++];
    }
    delete[] B;
}

void testIncrease()
{
    Vector<int> s;
    for (int i = 0; i != 10; ++i)
    {
        s.insert(0, i);
    }
    for (int i = 0; i != 10; ++i)
    {
        cout << s[i] << ' ';
    }
    cout << endl;
    increase(s);
    for (int i = 0; i != 10; ++i)
    {
        cout << s[i] << ' ';
    }
}
void testUniquify()
{
    Vector<int> s;
    s.insert(0, 1);
    s.insert(0, 1);
    s.insert(0, 1);
    s.insert(0, 2);
    s.insert(0, 2);
    s.insert(0, 2);
    s.insert(0, 2);
    s.insert(0, 3);
    s.insert(0, 3);
    s.insert(0, 3);
    s.insert(0, 3);

    for (int i = 0; i < s.size(); ++i)
    {
        cout << s[i] << ' ';
    }
}
void testMerge()
{
    Vector<int> s;
    for (int i = 0; i != 10; ++i)
    {
        s.insert(0, i);
    }
    increase(s);
    increase(s);
    increase(s);
    increase(s);
    increase(s);
    increase(s);
    increase(s);
    increase(s);
    increase(s);
    for (int i = 0; i != 10; ++i)
    {
        s.insert(0, i);
    }
    for (int i = 0; i != s.size(); ++i)
    {
        cout << s[i] << ' ';
    }
    cout << endl;
    s.sort(0, s.size());
    for (int i = 0; i != s.size(); ++i)
    {
        cout << s[i] << ' ';
    }
}

void test()
{
    //testIncrease();
    //testUniquify();
    testMerge();

    system("pause");
}

int main(void)
{
    test();

    return 0;
}