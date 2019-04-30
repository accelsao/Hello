#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,b[N],h[N],vis[N];
string s;
int main(){
	for(int i=0;i<26;i++)b[i]=h[i]=-1;
	cin>>n;
	while(n--){
		cin>>s;vis[s[0]-'a']=1;
		for(int i=1;i<s.size();i++){
			int u=s[i-1]-'a',v=s[i]-'a';
			vis[u]=vis[v]=1;
			if((~b[u]&&b[u]!=v)||(~h[v]&&h[v]!=u))return puts("NO"),0;
			b[u]=v,h[v]=u;
		}
	}
	int t=0;
	s="";
	for(int i=0;i<26;t+=vis[i++])
		if(vis[i]&&h[i]==-1)
			for(int j=i;~j;j=b[j])
				t--,s+=j+'a';
	if(t)puts("NO");
	else cout<<s<<endl;
}
