#include<iostream>
#include<string.h>
using namespace std;
class A {
	public:
		void getdata() { //输入数组元素
			cout<<"请输入集合中的元素：";
			gets(data);
		}
		void print( ) { //输出数组元素
			puts(data);
		}

		A operator +(A s1) { //重载"+"实现字符串的并集运算

			A temp;
			count=strlen(data);
			s1.count=strlen(s1.data);
			int i=0,j=0,k=0,x=0;
			for(i=0; i<count; i++) {
				temp.data[x]=data[i];
				x++;
			}
			for(j=0; j<s1.count; j++) {
				k=0;
				for(i=0; i<count; i++) {
					if(s1.data[j]==data[i])
						break;
					else if(s1.data[j]!=data[i])
						k++;
					if(k==count) {
						temp.data[x]=s1.data[j];
						x++;
					}

				}
			}

			temp.data[x]='\0';
			return temp;
		}

		A operator *(A s1) { //重载“*”实现字符串的交集运算
			A temp;
			count=strlen(data);
			s1.count=strlen(s1.data);
			int i=0,j=0,x=0;
			for(i=0; i<count; i++) {
				for(j=0; j<s1.count; j++) {
					if(data[i]==s1.data[j]) {
						temp.data[x]=data[i];
						x++;
					}
				}
			}
			temp.data[x]='\0';
			return temp;
		}

		A operator -(A s1) { //重载“-”实现字符串的差集运算
			A temp;
			count=strlen(data);
			s1.count=strlen(s1.data);
			int i=0,j=0,k=0;
			static int x=0;
			for(i=0; i<count; i++) {
				k=0;
				for(j=0; j<s1.count; j++) {
					if(data[i]==s1.data[j])
						break;
					else if(data[i]!=s1.data[j])
						k++;
					if(k==s1.count) {
						temp.data[x]=data[i];
						x++;
					}

				}
			}
			temp.data[x]='\0';
			return temp;

		}

	private:
		char data[100];
		int count;
};

int main(void) {
	A s1,s2,s3,s4;
	s1.getdata();
	s2.getdata();
	s3.getdata();

	cout<<"并集：";
	s4=s1+s2+s3;
	s4.print();

	cout<<"交集：";
	s4=s1*s2*s3;
	s4.print();

	cout<<"差集：";
	s4=s1-s2;
	s4.print();
}
