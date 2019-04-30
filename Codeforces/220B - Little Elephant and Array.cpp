#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,q,p[N],l[N],r[N],c[N],s[N],ans[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i],c[p[i]<=n?p[i]:0]++;
	for(int i=1;i<=q;i++)
		cin>>l[i]>>r[i];
	for(int i=1;i<=n;i++)
		if(i<=c[i]){
			for(int j=1;j<=n;j++)
				s[j]=s[j-1]+(p[j]==i);
			for(int j=1;j<=q;j++)
				if(s[r[j]]-s[l[j]-1]==i)
					ans[j]++;
		}
	for(int j=1;j<=q;j++)
		cout<<ans[j]<<endl;
}
