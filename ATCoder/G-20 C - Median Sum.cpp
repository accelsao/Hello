#include <bits/stdc++.h>
using namespace std;
bitset<20>v;
int main(){
	int N,A,S=0;
	scanf("%d",&N);
	v[0]=1;
	for(int i=N;i--;){
		scanf("%d",&A);
		S+=A;
		cout<<"1";cout<<v<<endl;
		cout<<"2"<<(v<<A)<<endl;
		v|=v<<A;
		cout<<"3"<<v<<endl;
	}
	for(int i=S/2;;i--)if(v[i])return printf("%d\n",S-i),0;
}
