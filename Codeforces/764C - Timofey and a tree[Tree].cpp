#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int p[N],n,u[N],v[N],c[N],d[N],e;
int main(){
	cin>>n;
	for(int i=1;i<n;i++)cin>>u[i]>>v[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<n;i++)if(c[u[i]]!=c[v[i]])e++,d[u[i]]++,d[v[i]]++;
	for(int i=1;i<=n;i++)if(e==d[i])return puts("YES"),cout<<i<<endl,0;
	puts("NO");
}
