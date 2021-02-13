#include<stdio.h>
#include<math.h>

#define N 1000

bool prime[N];

int main() {
	int i, j;
	for(i=2;i<N;i++)
	    prime[i]=true;
	for(i=3; i<N; i++)
		if(i%2)
		    prime[i]=true;
		else 
		    prime[i]=false;
	for(i=3; i<=sqrt(N); i++) {
		if(prime[i])
			for(j=i+i; j<N; j+=i) 
			    prime[j]=false;
	}
	for(i=2; i<N; i++)
		if( prime[i])
		    printf("%d ",i);

	return 0;
}
