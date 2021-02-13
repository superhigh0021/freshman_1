//编写一个程序，输入全班同学某门课考试成绩，计算平均成绩并找出其中最高分与最低分。
//提示：批量数据通常不事先规定输入的数据数量，而是以一个特殊的标志作为输入结束。程序根据结束标志统计人数
#include<iostream>
using namespace std;
int main(void)
{
	int total,i,max,min;
	float ave;
    int ch[100];
    printf("请输入全班同学的成绩(输入1000作为结尾)");

	for(i=0,total=0;;i++)
	{
		cin>>ch[i];
		if(ch[i]==1000)
		break;
		total+=ch[i];
		if(i==0)
		{
			max=ch[0];
			min=ch[0];
			}    
		max=max>ch[i]? max:ch[i];
		min=min<ch[i]? min:ch[i];
		  
	}
	ave=total/i;
	printf("平均成绩为%f,最高分为%d,最低分为%d",ave,max,min);
	return 0;
   
}


