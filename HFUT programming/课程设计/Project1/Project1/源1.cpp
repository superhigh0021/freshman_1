#include<cstdio>
#include<string.h>
#include<stdbool.h>
#include"statist.h"

void getline(FILE* pfile, char* pt) {
	while (!feof(pfile)) {
		*pt = fgetc(pfile);                         //fgetc()从文件指针指向的文件中读取一个字符，读取一个字节后，光标位置后移一个字节
		if (*pt == '\n') {	                        //成功读取完一行，直到换行符
			*pt = '\0';
			return;
		}
		pt++;
	}
	*pt = '\0';	                                    //如果还没有检测到换行符，文件已经结束，则在末尾添加终止符
}

char* mystrstr(char* s1, char* s2) {
	char* s, * sp1, * temp1, * temp2;
	int q_flag = 0;

	if (strstr(s1, "\"") == NULL) {	//如果没有发现引号
		s = strstr(s1, s2);
		return s;
	}
	else {	//如果发现引号
		sp1 = s1;
		while (*sp1) {
			temp1 = strstr(sp1, "\"");
			temp2 = strstr(sp1, s2);
			if ((temp1 != NULL) && (temp1 == sp1)) {
				if (q_flag == 0)
					q_flag = 1;
				else
					q_flag = 0;
			}
			if ((temp2 != NULL) && (q_flag == 0) && (temp2 == sp1))
				return sp1;
			sp1++;
		}
		return NULL;
	}
}

bool Isblank(char* pt) {
	if (*pt == '\0')
		return 1;
	return 0;
}

int Iscom(char* pt) {
	char* pt1, * pt2, * pt3;

	pt1 = mystrstr(pt, "//");
	pt2 = mystrstr(pt, "/*");
	pt3 = mystrstr(pt, "*/");
	if (com_flag == 0) {
		if ((pt2 != NULL) && (pt3 == NULL))	//如果只有/*表明注释开始
			com_flag = 1;
		if (pt1 == pt)	//双斜杠开头的注释
			return 1;
		else if (pt1 - pt > 0 || pt2 - pt > 0)	//有注释符号，但是不是顶头开始
			return 2;
		else if ((pt2 == pt) && ((pt3 != NULL && (*(pt3 + 2) == '\0')) || (pt3 == NULL)))	//以/*开头以*/结尾，或者以/*开头，没有检测到*/
			return 1;
		else if ((pt2 == pt) && (pt3 != NULL) && (*(pt3 + 2) != '\0'))	//以/*开头但是没有以*/结尾
			return 2;
		else if (pt1 == NULL || pt2 == NULL)	//没有检测到注释符号
			return 0;
	}
	else if (com_flag == 1) {
		if (pt3 != NULL) {
			com_flag = 0;
			return 1;
		}
		printf("\nYYYY\n");
		return 1;	//如果com_flag==1，且没有检测到*/则是一句注释
	}
}

bool Isfunc(char* pt) {
	char* pt1, * pt2, * pt3, * pt4, * pt5, * pt6;


	pt1 = mystrstr(pt, "(");
	pt2 = mystrstr(pt, ";");
	pt3 = mystrstr(pt, "if");
	pt4 = mystrstr(pt, "while");
	pt5 = mystrstr(pt, "for");
	pt6 = mystrstr(pt, "switch");
	if (pt1 != NULL && pt2 == NULL && pt3 == NULL && pt4 == NULL && pt5 == NULL && pt6 == NULL)
		return true;
	return false;
}

bool Qtycheck(int* pt) { //只允许输入一个1到9的数字
	char temp[3];
	char c;
	fflush(stdin);
	gets(temp);
	if (temp[0] > '0' && temp[0] <= '9' && temp[1] == '\0')
		*pt = (int)(temp[0] - 48);
	else {
		fflush(stdin);
		printf("Please re-enter the file quantity(0<n<10):");
		return false;
	}
	return true;
}
