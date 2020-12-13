// 编程实现数组的排序:将有15个元素的整型数组按从小到大的次序排序
#include<iostream>
using namespace std;

int main(void)
{
	int temp,n=15;
	int a[15]={45,12,62,98,24,17,6,38,94,28,23,4,9,66,82};
	for (int i=1;i<=n-1;i++)
	{
	for (int j=0;j<=n-i;j++)
        if (a[j]>a[j+1])  
        {
            temp=a[j];a[j]=a[j+1];a[j+1]=temp;
        }
   }
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
	
	return 0;

}
