#include<iostream>
using namespace std;

int main(void){
    int A[5]={7,9,10,23,27};
    int B[5]={0};
    for(int i=0;i<5;B[i++]=A[i]);

    for(int i=0;i<5;++i)
    cout<<B[i]<<' ';
    system("pause");
    return 0;
}
