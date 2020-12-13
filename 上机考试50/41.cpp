#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int nletter[26];
	char ch;
	int i;
	for(i=0; i<26; i++)
	    nletter[i]=0;
	do {
		ch = getchar();
		if(ch>='A'&&ch<='Z')
		    nletter[ch-'A']++;
		if(ch>='a'&&ch<='z')
		    nletter[ch-'a']++;
	} while(ch!='?');
	for(i=0; i<26; i++)
		if (nletter[i])
		    cout<<char(i+'A')<<' '<<nletter[i]<<'\t';
	cout<<endl;
}
