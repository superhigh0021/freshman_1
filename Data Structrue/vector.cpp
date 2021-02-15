#include <iostream>
using namespace std;

typedef int Rank;          //秩
#define DEFAULT_CAPACITY 3 //默认初始容量

template <typename T>
class Vector
{
protected:
    Rank _size;
    int _capacity;
    T *_elem;                                    //规模、容量、数据区
    void copyFrom(T const *A, Rank lo, Rank hi); //复制数组区间A[lo,hi)
    void expand();                               //空间不足时扩容
    void shrink();                               //装填因子过小时压缩
    bool bubble(Rank lo, Rank hi);               //扫描交换
    void bubbleSort(Rank lo, Rank hi);           //起泡排序算法
    Rank max(Rank lo, Rank hi);                  //选取最大元素
    void selectionSort(Rank lo, Rank hi);        //选择排序算法
    void merge(Rank lo, Rank hi);                //归并算法
    void mergeSort(Rank lo, Rank hi);            //归并排序算法
    Rank partition(Rank lo, Rank hi);            //轴点构造算法
    void quickSort(Rank lo, Rank hi);            //快速排序算法
    void heapSort(Rank lo, Rank hi);             //堆排序
public:
    //构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    } //容量为c、规模为s、所有元素初始为v
    Vector(T const *A, Rank n)
    {
        copyFrom(A, 0, n);
    } //数组整体复制
    Vector(T const *A, Rank lo, Rank hi)
    {
        copyFrom(A, lo, hi);
    } //区间
    Vector(Vector<T> const &V)
    {
        copyFrom(V._elem, 0, V._size);
    } //向量整体复制
    Vector(Vector<T> const &V, Rank lo, Rank hi)
    {
        copyFrom(V._elem, lo, hi);
    } //区间
      //析构函数
    ~Vector()
    {
        delete[] _elem;
    }
    //只读访问接口
    Rank size() const
    {
        return _size;
    } //规模
    bool empty() const
    {
        return !_size;
    }                       //判空
    int disordered() const; //判断向量是否是否已经排序
    Rank find(T const &e) const
    {
        return find(e, 0, _size);
    }                                              //无序向量整体查找
    Rank find(T const &e, Rank lo, Rank hi) const; //无序向量区间查找
    Rank search(T const &e) const                  //有序向量整体查找
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const;     //有序向量区间查找
                                                         // 可写访问接口
    T &operator[](Rank r);                               //重载下标操作符，可以类似于数组形式引用各元素
    const T &operator[](Rank r) const;                   //仅限于做右值的重载版本
    Vector<T> &operator=(const Vector<T> &);             //重载赋值操作符，以便直接克隆向量
    T remove(Rank r);                                    //删除秩为r的元素
    int remove(Rank lo, Rank hi);                        //删除秩在区间[lo, hi)之内的元素
    Rank insert(Rank r, T const &e);                     //插入元素
    Rank insert(T const &e) { return insert(_size, e); } //默认作为末元素插入
    void sort(Rank lo, Rank hi);                         //对[lo, hi)排序
    void sort() { sort(0, _size); }                      //整体排序
    void unsort(Rank lo, Rank hi);                       //对[lo, hi)置乱
    void unsort() { unsort(0, _size); }                  //整体置乱
    int deduplicate();                                   //无序去重
    int uniquify();                                      //有序去重
                                                         // 遍历
    void traverse(void (*)(T &));                        //遍历（使用函数指针，只读或局部性修改）
    template <typename VST>
    void traverse(VST &); //遍历（使用函数对象，可全局性修改）
};

template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0; //分配空间 规模清零
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

template <typename T> //无需向量的顺序查找：返回最后一个元素e的位置；失败时，返回lo-1
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const
{
    while ((lo < hi--) && (e != _elem[hi]))
        return hi; //若hi<lo 则意味着失败 否则hi即命中元素的秩
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
        _elem[lo++] = _elem[hi++]; //妙啊，牛逼克拉斯
    _size = lo;
    this->shrink();
    return hi - lo; //返回被删除元素的数目
}

template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    this->remove(r, r + 1);
    return e; //返回被删除元素
}

template <typename T> //妙啊艹
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
        visit(_elem[i]); //借助函数对象实现，妙啊
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