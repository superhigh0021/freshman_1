#define SIZE_N 100
#define SIZE_L 200
#define NUM_F 9
#define title "------------------------Life is a Fight-----------------------------------"

extern bool com_flag;

void getline(FILE* pfile, char* pt);
char* clearblank(char* pt);
char* mystrstr(char* s1, char* s2);
bool Isblank(char* pt);
int Iscom(char* pt);
bool Isfunc(char* pt);
bool Qtycheck(int* pt);
#pragma once
