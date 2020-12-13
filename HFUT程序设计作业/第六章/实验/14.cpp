//输入三个整数，按由小到大的顺序输出，然后将程序改为:输入三个字符串，按由小到大的顺序输出
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100
int main()
{
  char a[M],b[M],c[M];
  char *p,*q,*t;
  char x[M];
  printf("请输入三个字符串:\n");
  gets(a);
  gets(b);
  gets(c);
  p=a;
  q=b;
  t=c;
 if((strcmp(p,q))>0)
 {
      strcpy(x,p);
	  strcpy(p,q);
      strcpy(q,x);
 
 }
 if((strcmp(p,t))>0)
 {
      strcpy(x,p);
	  strcpy(p,t);
      strcpy(t,x);
 
 }
 if((strcmp(q,t))>0)
 {
      strcpy(x,q);
	  strcpy(q,t);
      strcpy(t,x);
 
 }
 
  
  printf("请输出由小到大排序好的三个字符串:%s\t%s\t%s\n",p,q,t);
  return 0;
}

