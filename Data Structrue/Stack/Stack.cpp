#include <iostream>
using namespace std;
#include"vector.h"

template <typename T>
class Stack:public Vector<T>
{
public:
    void push(T const &e) { insert(this->size(), e); }
    T pop() { return remove(this->size() - 1); }
    T &top() { return (*this)[this->size() - 1]; }
};