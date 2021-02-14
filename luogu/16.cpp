#include<iostream>
using namespace std;

int main(void){
	int M,N;
	cin>>M>>N;
	int in,cnt,n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
	for(int i=M;i<=N;++i){
		in=i;
		while(in!=0){
			cnt=in%10;
			switch(cnt){
				case 0:
					++n0;
					break;
				case 1:
					++n1;
					break;
				case 2:
					++n2;
					break;
				case 3:
					++n3;
					break;
				case 4:
					++n4;
					break;
				case 5:
					++n5;
					break;
				case 6:
					++n6;
					break;
				case 7:
					++n7;
					break;
				case 8:
					++n8;
					break;
				case 9:
					++n9;
					break;
			}
			in/=10;
		}
	}
	cout<<n0<<' '<<n1<<' '<<n2<<' '<<n3<<' '<<n4<<' '<<n5<<' '<<n6<<' '<<n7<<' '<<n8<<' '<<n9<<endl;
	system("pause");
	return 0;
}
