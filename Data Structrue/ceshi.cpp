#include<iostream>
#include<assert.h>
using namespace std;
 
typedef int Datatype;
typedef struct Node//��������һ�����ڵ�����������ﵥ��������һ���ͷ�������������ʹ��
{
     Datatype _data;
     struct Node* next;
     struct Node* prev;
}Node,*pNode;
 
class LinkList
{
private:
     pNode head;
public:
     LinkList()
    {
      head=NULL;
    }
 
 void pushback(Datatype x)
 {
      pNode p=new Node[sizeof(Node)];
      p->_data=x;
      p->next=NULL;
      if(head==NULL)
     {
        head=p;
        head->prev=NULL;
     }
     else
    {
        pNode cur=head;
        while(cur->next)
       {
           cur=cur->next;
       }
       cur->next=p;
       p->prev=cur;
    }
 }
 
 void pushfront(Datatype x)
 {
      pNode tmp=new Node[sizeof(Node)];
      if(head==NULL)
     {
        tmp->_data=x;
        head=tmp;
        head->next= NULL;
        head->prev=NULL;
    }
      else
   {
     //����Ҫ��ͷ���ǰ�ٲ���һ����㣬��Ҫ�ȴ���һ���µĽ�㣬��ͷ����ֵ�������½ڵ㣬Ȼ�����½ڵ����
     //�����ָ��ͷ������һ����㣬�����½ڵ��prevָ��ͷ��㣬�����ͽ��½ڵ���ԭ���������ں��ˣ�Ȼ����
     //�ǽ�ͷ�������ݻ���x���ɡ�
        tmp->_data=head->_data;
        tmp->next=head->next;
        tmp->prev=head;//
        head->next=tmp;
        head->_data=x;
  }
 }
 void popback()
 {
      if(head!=NULL)
     {
       pNode cur=head;
       pNode pre=NULL;
       while(cur->next)
     {
       pre=cur;
       cur=cur->next;
     }
     delete[] cur;
     cur=NULL;
     pre->next=NULL;//һ��Ҫ��pre->next��Ϊ��,ǰ��һ������ǽ�cur��ֵ��Ϊ�գ���ʱpre->next��ָ��ԭ�����ǿ�ռ�
  }
 }
 
 void popfront()
 {
      if(head!=NULL)
     {
        if(head->next==NULL)
       {
          delete[] head;
          head=NULL;
       }
     else
      {
         pNode del=head;
         head=head->next;
         delete[] del;
         del=NULL;//���ｫdel��Ϊ�տ��Է�ֹ����ΪҰָ��
      }
    }
 }
 
 pNode find(Datatype x)
 {
      if(head==NULL)
    {
      return NULL;
    }
      else
    {
       pNode cur=head;
       while(cur)
      {
         if(x==cur->_data)
        {
          return cur;
        }
         cur=cur->next;
      }
    return NULL;
  }
 }
 
 void insert(pNode pos,Datatype x)
 {
      assert(pos);//��ֹposΪ��ָ��
      if(head==NULL)
     {
       return ;
     }
      else
     {
        pNode cur=head;
        if(head==pos)
       {
        pushfront(x);
       }
       else
       {
            while(cur)
          {
             if(cur==pos)
            {
             pNode tmp=new Node[sizeof(Node)];
             tmp->_data=cur->_data;
             tmp->next=cur->next;
             tmp->prev=cur;
             cur->_data=x;
             cur->next=tmp;
             return ;//insert�ɹ���Ҫ����ֱ�ӷ��ؽ�������
            }
            cur=cur->next;
         }
         cout<<"û���ҵ��������"<<endl;
      }
   }
 }
 
 void erase(pNode pos)//ɾ��ָ��λ�õĽ��
 {
      assert(pos);
      if(head==NULL)
     {
       return;
     }
     else
    {
        if(pos==head)
       {
         popfront();
       }
       else
      {
         pNode del=head->next;
         pNode pre=head;
         while(del)
        {
           if(del==pos)
           {
               if(del->next!=NULL)
             {
                pre->next=del->next;
                del->next->prev=pre;
                delete[] del;
                del=NULL;
             }
             else
            {
               delete[] del;
               pre->next=NULL;
            }
             return;
          }
         del=del->next;
         pre=pre->next;
      }
   }
  }
 }
 
 int use_count()//���������н�������
 {
      int count=0;
      pNode cur=head;
      while(cur)
     {
       cur=cur->next;
       count++;
     }
     return count;
 }
 
 void display()//��ӡ����
 {
      pNode cur=head;
      while(cur!=NULL)
     {
       cout<<cur->_data<<endl;
       cur=cur->next;
     }
 }
 
 ~LinkList()
 {
      pNode cur=head;
      while(cur!=NULL)
     {
         pNode Next=cur->next;
         delete cur;
         cur=Next;
         if(cur!=NULL)
        {
          Next=Next->next;
        }
         else
           break;
     }
 }
};
 
void test()
{
     LinkList ls1;
     cout<<"push_back:";
     ls1.pushback(1);
     ls1.pushback(2);
     ls1.pushback(3);
     ls1.pushfront(0);
     cout<<"display"<<endl;
     ls1.display();
     ls1.popback();
     cout<<"display1"<<endl;
     ls1.display();
     ls1.popfront();
     cout<<"display2"<<endl;
     ls1.display();
 
     pNode ret=ls1.find(2);
     if(ret==NULL)
    {
      cout<<"û���ҵ�"<<endl;
    }
     else
    {
      cout<<"finddata:"<<ret->_data<<endl;
      cout<<ret<< endl;
      cout<<endl;
    }
    ls1.insert(ret,5);
    ls1.display();
    pNode ret2=ls1.find(2);
    ls1.erase(ret2);
    ls1.display();
    int ret3=ls1.use_count();
    cout<<ret3<<endl;
}
 
int main()
{
     test();
     getchar();
     return 0;
}