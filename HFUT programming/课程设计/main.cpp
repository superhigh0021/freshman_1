#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"statist.h"
#include<stdlib.h>//system()的头文件

bool com_flag;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	FILE* in,*log;      //两个文件指针，前者读入源程序，后者写入结果
	char con;
	char temp[SIZE_L + 1];
	char name[SIZE_N];
	char* pt;
	char* name_t;
	int* result;

	int n = 0;
	struct FIL {
		int cod;
		int blk;
		int com;
		int fct;
	} fil = { 0, 0, 0, 0 };
	com_flag = 0;
	do {
		printf("%s", title);                                          //在开头打印"------------------------Life is a Fight-----------------------------------"
		printf("\n\n\nPlease enter the file quantity(0<n<10):");      //提示输入文件个数
		while (!Qtycheck(&n));                                        //调用Qtycheck()函数，检查1<n<9
		name_t=(char*)malloc(n*sizeof(name));                                           //动态分配内存，这边看不懂配合下面具体操作看。通过动态分配实现数组的上限可控
		result = (int*)malloc(n*4*sizeof(int));
		log = fopen("log.txt", "w");
		fprintf(log, "%s\n\n\n", title);                              //在log.txt中写入"------------------------Life is a Fight-----------------------------------"
		for (int i = 0; i < n; i++) {                                 //用循环结构读取n个文件
			printf("please enter file \"%d\" name:", i+1);
			gets(name_t + i*SIZE_N);                                  //scanf和文件指针同时操作，可以实现在DOS命令行载入文件
			in = fopen(name_t + i*SIZE_N, "r");
			while (in==NULL) {                                        //当读取成功时
				fflush(stdin);                                        //清空缓冲区，以便下一次输入
				printf("please re-enter file \"%d\" name:", i+1);
				gets(name_t + i*SIZE_N);
				in = fopen(name_t + i*SIZE_N, "r");
			}
			fclose(in);                                               //现在用不着，先关了
		}
		for (int i = 0; i < n; i++) {                                 //遍历输入的文件
			in = fopen(name_t + i*SIZE_N, "r");
			while (!feof(in)) {                                       //feof()识别文件结尾，!feof()表示没有结束。先读取再判断
				getline(in, temp);    //每一次调用getline，文件指针就会指到这一行的行尾 
				pt = clearspace(temp);
				if (Isblank(pt) == 1 && com_flag == 0) {
					fil.blk++;
					continue;
				} else if (Iscom(pt) == 1) {
					fil.com++;
					continue;
				} else if (Iscom(pt) == 2 && Isfunc(pt) == 0)
					fil.com++;
				else if (Iscom(pt) == 2 && Isfunc(pt)  == 1) {
					fil.com++;
					fil.fct++;
					fil.cod++;
					fprintf(log, "%s	%s\n", name_t + i*SIZE_N, temp);
					continue;
				} else if (Isfunc(pt) == 1) {
					fil.fct++;
					fprintf(log, "%s	%s\n", name_t + i*SIZE_N, temp);
				}
				fil.cod++;
			}
			*(result + 4 * i) = fil.blk;
			*(result + 4 * i + 1) = fil.cod;
			*(result + 4 * i + 2) = fil.com;
			*(result + 4 * i + 3) = fil.fct;
			fil.blk = 0;
			fil.cod = 0;
			fil.com = 0;
			fil.fct = 0;
			com_flag = 0;
			fclose(in);
			if (fil.fct)
				fprintf(log, "\n\n\n");
		}
		fprintf(log, "%s", "\n\n\n==========================================================");
		printf("==========================================================");
		printf("\nFile No.	Blank	Code	Commen	Function\n");
		fprintf(log, "\n%s\n", "File No.	Blank	Code	Commen	Function");
		for (int i = 0; i < n; i++) {
			printf("%d		%d	%d	%d	%d\n", i + 1, *(result + 4 * i), *(result + 4 * i + 1), *(result + 4 * i + 2), *(result + 4 * i + 3));
			fprintf(log, "%d		%d	%d	%d	%d\n", i + 1, *(result + 4 * i), *(result + 4 * i + 1), *(result + 4 * i + 2), *(result + 4 * i + 3));
		}
		fclose(log);
		free(name_t);
		free(result);
		printf("\n\n\nPress 'Y' to continue\n");
		fflush(stdin);
		con = getchar();
		printf("\n\n\n");
	} while (con=='Y'||con=='y');
	system("pause");

	return 0;
}
