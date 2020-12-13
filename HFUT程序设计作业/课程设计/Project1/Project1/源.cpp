#include<cstdio>
#include<string.h>
#include<stdbool.h>
#include"statist.h"
#include<stdlib.h>//system()的头文件
#include<malloc.h>

bool com_flag;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	FILE* in, * log;      //两个文件指针，前者读入源程序，后者写入结果
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
		printf("\n\n\nPlease enter the file quantity(0<n<10):");      //打印文件的数量
		while (!Qtycheck(&n));                                        //调用Qtycheck函数，检查输入的数是否满足1<n<9
		name_t = (char*)malloc(n * sizeof(name));                       //动态分配内存，这边看不懂配合下面具体操作看。通过动态分配实现数组的上线可控
		result = (int*)malloc(n * 4 * sizeof(int));
		log = fopen("log.txt", "w");                                  //通过 *log这个文件指针打开一个文件，如果有就直接写入，如果没有就先创建再写入
		fprintf(log, "%s\n\n\n", title);                              //在文本里打印"------------------------Life is a Fight-----------------------------------"
		for (int i = 0; i < n; i++) {                                 //用循环结构读取n个文件
			printf("please enter file \"%d\" name:", i + 1);            //提示用户输入文件名
			scanf("%s", name_t + i * SIZE_N);                           //用递增的 i 储存不同的文件，方便用for打开
			in = fopen(name_t + i * SIZE_N, "r");
			while (in == NULL) {                                        //当输入的这个文件有问题，即in为空指针，就重新输入
				fflush(stdin);                                        //清空缓冲区，以便下一次输入
				printf("please re-enter file \"%d\" name:", i + 1);
				scanf("%s", name_t + i * SIZE_N);
				in = fopen(name_t + i * SIZE_N, "r");
			}
			fclose(in);                                               //现在用不着，先关了
		}
		for (int i = 0; i < n; i++) {                                 //遍历输入的文件
			in = fopen(name_t + i * SIZE_N, "r");                       //打开文件（只读）
			while (!feof(in)) {                                       //feof()识别文件结尾，!feof()表示没有结束,这个函数一次读取一行，先读取再判断 
				getline(in, temp);                                    //调用getline()函数，传入in这个文件指针和temp数组的首元素地址
				pt = temp;                                            //一直用数组的首元素地址不太好，用一个字符替代它
				if (Isblank(pt) == 1 && com_flag == 0) {
					fil.blk++;
					continue;
				}
				else if (Iscom(pt) == 1) {
					fil.com++;
					continue;
				}
				else if (Iscom(pt) == 2 && Isfunc(pt) == 0)
					fil.com++;
				else if (Iscom(pt) == 2 && Isfunc(pt) == 1) {
					fil.com++;
					fil.fct++;
					fil.cod++;
					fprintf(log, "%s	%s\n", name_t + i * SIZE_N, temp);
					continue;
				}
				else if (Isfunc(pt) == 1) {
					fil.fct++;
					fprintf(log, "%s	%s\n", name_t + i * SIZE_N, temp);
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
	} while (con == 'Y' || con == 'y');
	system("pause");

	return 0;
}