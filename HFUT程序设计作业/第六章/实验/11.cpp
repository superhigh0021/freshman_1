//编程求一组整数的最大公因子和最小公倍数。
#include<stdio.h>
#include<stdlib.h>
void get_number(int array[],int b)             
{
	
	int i=0;
	
	for (i=0;i<=b-1;i++)
	{
		printf("请输入第%d个数:",i+1);
		scanf("%d",&array[i]);
		while(array[i]<=0)
		{
			printf("请输入正整数\n");
			scanf("%d",&array[i]);
		}
	}
	printf("输入成功\n");
	printf("\n");

}

void BubbleSort(int array[],int n)
{
	int i,j,temp;                    

	 for(i=0; i<n-1; i++)            
	{

		for(j=0; j<n-1-i; j++)
		{
		   if(array[j]>array[j+1])
		   {
			temp=array[j];
			array[j]=array[j+1];
			array[j+1]=temp;
		   }
		}
	}
	printf("排序后的这几个数:");
	for(i=0;i<n;i++) 
	{
		printf("\t%d",array[i]);
	}
	
	
}

void manage(int array[],int b)                  
{
	int e; 
	e=array[0];
	int c=1;
	int d=0;
	int f;
	f=array[b-1];
	while(c!=0)
	{
		c=0;
		for(d=0;d<b;d++)
		{
			if(array[d]%e==0)
			{
				c+=0;
		    }
			else
			{
				c+=1;
			}
		}
		if(c!=0)	e--;
	}
	printf("\n");
	printf("\n这几个数的最大公因数为:\t%d\n",e);

	c=1;
	while(c!=0)
	{
		c=0;
		for(d=0;d<b;d++)
		{
			if(f%array[d]==0)
			{
				c+=0;
		
			}
			else
			{
				c+=1;
			}
		}
		if(c!=0)	f++;
	}
	printf("\n这几个数的最小公倍数为:\t%d\n\n\n\n",f);
}

void home()
{
	int a[50];
	int b;

	printf("请输入你要得到几个数的最大公因数：");
	scanf("%d",&b);
	get_number(a,b); 
	BubbleSort(a,b);  
	manage(a,b);         
}

int main()
{

	home();
	
	return 0;
}



