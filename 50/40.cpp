#include<iostream>
#include<math.h>
using namespace std;
int func(int n) {
	int i,k=(int)sqrt(n)+1;
	for(i=2; i<k; i++)
		if(n%i==0)
		break;
	if(i==k)
		return 1;
	else
		return 0;
}
int main() {
	int m,i,j,h;
	for(m=0; m<=2000; m++) {
		h=0;
		if(func(m)==1) {
			for(i=1;; i++) {
				if((func(m+i)==0)&&(m+i<=2000))
				    h++;
				else
				    break;
			}
			m+=i;
			if(h>=9) {
				for(j=i-1; j>=-1; j--)
				    cout<<m-j<<' ';
				cout<<"\n";
			}
		} 
		else
		    continue;
	}
	return 0;
}
