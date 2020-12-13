#include <stdio.h>
#include <stdlib.h>
extern unsigned int rand0(void);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int count;
	
	for(count = 0; count < 5;count++)
	    printf("%d\n", rand0());
	
	return 0;
}
