#include <stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;

void cal(int (*p)[3] )
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i != j)
			{
				int temp = p[i][j];
				p[i][j] = p[j][i];
				p[j][i] = temp;
			}

		}
	}
	
}
int main()
{
	int a[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	};
	cal(&a[0]);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	};
	return 0;
}

