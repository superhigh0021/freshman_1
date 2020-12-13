//100匹马驮100担货，大马一匹驮3担，中马一匹驮2担，小马2匹驮1担。试编程计算大、中、小马的数目。
#include<iostream>
using namespace std;
int main(void)
{
	int l,m,s;
	for(l=0;l<34;l++)
	{
		for(m=0;m<=50;m++)
		{
			for(s=0;s<=100;s++)
			{
				if(l+m+s==100&&3*l+2*m+s/2==100)
				printf("大马%d匹，中马%d匹，小马%d匹\n",l,m,s);
			}
		}
	}
	return 0;
}
