#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1; 
vector<int>g[N];
int n,x,m,in[N],out[N],T,lz[N*4],s[N*4];
string op;
void dfs(int u){
	in[u]=++T;
	for(auto v:g[u])
		dfs(v);
	out[u]=T;
}
void pd(int rt,int l,int r){
	if(lz[rt]){
		s[rt]=r-l+1-s[rt];
		if(l!=r)
			lz[rt<<1]^=1,lz[rt<<1|1]^=1;
		lz[rt]=0;
	}
}
void pw(int rt,int l,int r,int L,int R){
	pd(rt,l,r);
	if(l>R||r<L)return;
	if(l>=L&&r<=R){
		lz[rt]^=1;
		pd(rt,l,r);
		return ;
	}
	int m=l+r>>1;
	pw(rt<<1,l,m,L,R);
	pw(rt<<1|1,m+1,r,L,R);
	s[rt]=s[rt<<1]+s[rt<<1|1];
}
int sum(int rt,int l,int r,int L,int R){
	pd(rt,l,r);
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)
		return s[rt];
	int m=l+r>>1;
	return sum(rt<<1,l,m,L,R)+sum(rt<<1|1,m+1,r,L,R);
}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>x;
		g[x].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x)
			pw(1,1,n,in[i],in[i]);
	}
	cin>>m;
	while(m--){
		cin>>op>>x;
		if(op[0]=='p')
			pw(1,1,n,in[x],out[x]);
		else
			cout<<sum(1,1,n,in[x],out[x])<<endl;
	}
}
