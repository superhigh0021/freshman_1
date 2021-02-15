#include <iostream>
using namespace std;

typedef int Rank;          //��
#define DEFAULT_CAPACITY 3 //Ĭ�ϳ�ʼ����

template <typename T>
class Vector
{
protected:
    Rank _size;
    int _capacity;
    T *_elem;                                    //��ģ��������������
    void copyFrom(T const *A, Rank lo, Rank hi); //������������A[lo,hi)
    void expand();                               //�ռ䲻��ʱ����
    void shrink();                               //װ�����ӹ�Сʱѹ��
    bool bubble(Rank lo, Rank hi);               //ɨ�轻��
    void bubbleSort(Rank lo, Rank hi);           //���������㷨
    Rank max(Rank lo, Rank hi);                  //ѡȡ���Ԫ��
    void selectionSort(Rank lo, Rank hi);        //ѡ�������㷨
    void merge(Rank lo, Rank hi);                //�鲢�㷨
    void mergeSort(Rank lo, Rank hi);            //�鲢�����㷨
    Rank partition(Rank lo, Rank hi);            //��㹹���㷨
    void quickSort(Rank lo, Rank hi);            //���������㷨
    void heapSort(Rank lo, Rank hi);             //������
public:
    //���캯��
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    } //����Ϊc����ģΪs������Ԫ�س�ʼΪv
    Vector(T const *A, Rank n)
    {
        copyFrom(A, 0, n);
    } //�������帴��
    Vector(T const *A, Rank lo, Rank hi)
    {
        copyFrom(A, lo, hi);
    } //����
    Vector(Vector<T> const &V)
    {
        copyFrom(V._elem, 0, V._size);
    } //�������帴��
    Vector(Vector<T> const &V, Rank lo, Rank hi)
    {
        copyFrom(V._elem, lo, hi);
    } //����
      //��������
    ~Vector()
    {
        delete[] _elem;
    }
    //ֻ�����ʽӿ�
    Rank size() const
    {
        return _size;
    } //��ģ
    bool empty() const
    {
        return !_size;
    }                       //�п�
    int disordered() const; //�ж������Ƿ��Ƿ��Ѿ�����
    Rank find(T const &e) const
    {
        return find(e, 0, _size);
    }                                              //���������������
    Rank find(T const &e, Rank lo, Rank hi) const; //���������������
    Rank search(T const &e) const                  //���������������
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const;     //���������������
                                                         // ��д���ʽӿ�
    T &operator[](Rank r);                               //�����±������������������������ʽ���ø�Ԫ��
    const T &operator[](Rank r) const;                   //����������ֵ�����ذ汾
    Vector<T> &operator=(const Vector<T> &);             //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
    T remove(Rank r);                                    //ɾ����Ϊr��Ԫ��
    int remove(Rank lo, Rank hi);                        //ɾ����������[lo, hi)֮�ڵ�Ԫ��
    Rank insert(Rank r, T const &e);                     //����Ԫ��
    Rank insert(T const &e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز���
    void sort(Rank lo, Rank hi);                         //��[lo, hi)����
    void sort() { sort(0, _size); }                      //��������
    void unsort(Rank lo, Rank hi);                       //��[lo, hi)����
    void unsort() { unsort(0, _size); }                  //��������
    int deduplicate();                                   //����ȥ��
    int uniquify();                                      //����ȥ��
                                                         // ����
    void traverse(void (*)(T &));                        //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
    template <typename VST>
    void traverse(VST &); //������ʹ�ú������󣬿�ȫ�����޸ģ�
};

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
static bool lt(const T &a, const T &b)
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

void test01()
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
    system("pause");
}

int main(void)
{
    test01();
    
    return 0;
}