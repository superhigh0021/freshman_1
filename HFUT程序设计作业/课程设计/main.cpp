#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"statist.h"
#include<stdlib.h>//system()��ͷ�ļ�

bool com_flag;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	FILE* in,*log;      //�����ļ�ָ�룬ǰ�߶���Դ���򣬺���д����
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
		printf("%s", title);                                          //�ڿ�ͷ��ӡ"------------------------Life is a Fight-----------------------------------"
		printf("\n\n\nPlease enter the file quantity(0<n<10):");      //��ʾ�����ļ�����
		while (!Qtycheck(&n));                                        //����Qtycheck()���������1<n<9
		name_t=(char*)malloc(n*sizeof(name));                                           //��̬�����ڴ棬��߿����������������������ͨ����̬����ʵ����������޿ɿ�
		result = (int*)malloc(n*4*sizeof(int));
		log = fopen("log.txt", "w");
		fprintf(log, "%s\n\n\n", title);                              //��log.txt��д��"------------------------Life is a Fight-----------------------------------"
		for (int i = 0; i < n; i++) {                                 //��ѭ���ṹ��ȡn���ļ�
			printf("please enter file \"%d\" name:", i+1);
			gets(name_t + i*SIZE_N);                                  //scanf���ļ�ָ��ͬʱ����������ʵ����DOS�����������ļ�
			in = fopen(name_t + i*SIZE_N, "r");
			while (in==NULL) {                                        //����ȡ�ɹ�ʱ
				fflush(stdin);                                        //��ջ��������Ա���һ������
				printf("please re-enter file \"%d\" name:", i+1);
				gets(name_t + i*SIZE_N);
				in = fopen(name_t + i*SIZE_N, "r");
			}
			fclose(in);                                               //�����ò��ţ��ȹ���
		}
		for (int i = 0; i < n; i++) {                                 //����������ļ�
			in = fopen(name_t + i*SIZE_N, "r");
			while (!feof(in)) {                                       //feof()ʶ���ļ���β��!feof()��ʾû�н������ȶ�ȡ���ж�
				getline(in, temp);    //ÿһ�ε���getline���ļ�ָ��ͻ�ָ����һ�е���β 
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
