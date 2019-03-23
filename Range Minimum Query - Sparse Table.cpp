/*
RMQ
5
0 2 3 5 2
3
0 2
1 4
4 5
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int a[N];
int f[N][25];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)f[i][0]=a[i];
	
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<(j-1))<n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		int i=0;
		while(1<<(i+1)<=r-l+1)i++;
		int ans=min(f[l][i],f[r-(1<<i)+1][i]);
		cout<<ans<<endl;
	}
	
		
}

