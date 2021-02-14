#include<bits/stdc++.h>
using namespace std;
int main(){
    float a,b,c,p;
    cin>>a>>b>>c;//?????????
    p=(a+b+c)/2;
    printf("%.1f",(float)sqrt(p*(p-a)*(p-b)*(p-c)));//??,sqrt???
}
