#include<iostream>
#include<string.h>
using namespace std;
class A {
	public:
		void getdata() { //��������Ԫ��
			cout<<"�����뼯���е�Ԫ�أ�";
			gets(data);
		}
		void print( ) { //�������Ԫ��
			puts(data);
		}

		A operator +(A s1) { //����"+"ʵ���ַ����Ĳ�������

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

		A operator *(A s1) { //���ء�*��ʵ���ַ����Ľ�������
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

		A operator -(A s1) { //���ء�-��ʵ���ַ����Ĳ����
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

	cout<<"������";
	s4=s1+s2+s3;
	s4.print();

	cout<<"������";
	s4=s1*s2*s3;
	s4.print();

	cout<<"���";
	s4=s1-s2;
	s4.print();
}
