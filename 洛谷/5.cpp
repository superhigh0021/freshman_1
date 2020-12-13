#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        
        cout << 2 + 4 << ' ' << 10 - 2 - 4;
    } else if (T == 3) {
        printf("%d\n%d\n%d", (14-14%4)/4, 14-14%4, 14%4);
    } else if (T == 4) {
        printf("%.3lf", 166.667);
    } else if (T == 5) {
        printf("15");
    } else if (T == 6) {
        printf("10.8167");
    } else if (T == 7) {
        printf("110\n90\n0");
    } else if (T == 8) {
        printf("31.4159\n78.5398\n523.599");
    } else if (T == 9) {
        printf("22");
    } else if (T == 10) {
        printf("9");
    } else if (T == 11) {
        printf("33.3333");
    } else if (T == 12) {
        printf("13\nR");
    } else if (T == 13) {
       printf("16");
    } else if (T == 14) {
       printf("50");
    }
    return 0;
}
