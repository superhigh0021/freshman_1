#include<iostream>
#define BinNodePosi(T) BinNode<T> *
#define stature(p) ((p) ? (p)->height : -1)
typedef enum
{
    RB_RED,
    RB_BLACK
} RBColor;

template <typename T>
struct BinNode
{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;
    int npl;
    RBColor color;
//���캯��
    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
//�ӿڲ���
    int size(); //ͳ�Ƶ�ǰ�ڵ�������
    BinNodePosi(T) insertAsLc(const T &);
    BinNodePosi(T) insertAsRc(const T &);
    BinNodePosi(T) succ();
    template <typename VST>
    void travLevel(VST &); //������α���
    template <typename VST>
    void travPre(VST &); //�����������
    template <typename VST>
    void travIn(VST &); //�����������
    template <typename VST>
    void travPost(VST &); //�����������
//�Ƚ������е���
    bool operator<(BinNode const &bn){return data < bn.data;};
    bool operator==(BinNode const &bn){return data == bn.data;};
};