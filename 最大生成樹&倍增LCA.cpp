#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=5e4+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
struct road{
	int x,y,c;
};
struct tr{
	int to,c;
};
vector<road>E;
int n,m;
bool cmp(road a,road b){
	return a.c>b.c;
}
int p[N];
vector<tr>Tr[N];
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
void kruskal(){
	int c=0;
	REP(i,m){
		//cout<<E[i].c;
		int x=find(E[i].x),y=find(E[i].y);
		if(x!=y){
			p[x]=y;
			Tr[E[i].x].PB(tr{E[i].y,E[i].c});
			Tr[E[i].y].PB(tr{E[i].x,E[i].c});
			c++;
			if(c==n-1)break;
		}
	}
}
int dep[N];
int fa[N][21],w[N][21];
void dfs(int u){
	//cout<<u<<endl;
	for(auto i:Tr[u]){
		int v=i.to;
		if(dep[v])continue;
		dep[v]=dep[u]+1;
		fa[v][0]=u;
		w[v][0]=i.c;
		dfs(v);
	}
}
int lca(int x,int y){
	int ans=1e9;
	if(dep[x]<dep[y])swap(x,y);
	int k=dep[x]-dep[y];
	for(int i=20;~i;i--)
		if(dep[fa[x][i]]>=dep[y])
			ans=min(ans,w[x][i]),x=fa[x][i];
	if(x==y)return ans;
	for(int i=20;~i;i--)
		if(fa[x][i]!=fa[y][i]){
			ans=min(ans,min(w[x][i],w[y][i]));
			x=fa[x][i],y=fa[y][i];
		}
	return min(ans,min(w[x][0],w[y][0]));
}
int main(){Accel
	cin>>n>>m;
	E.resize(m+1);
	REP(i,m)cin>>E[i].x>>E[i].y>>E[i].c;
	sort(ALL(E),cmp);
	//FOR(i,1,m)cout<<E[i].c<<endl;
	FOR(i,1,n)p[i]=i;
	kruskal();
	dep[1]=1;
	dfs(1);
	FOR(i,1,n)
	if(!dep[i]){
		dep[i]=1;
		dfs(i);
	}
	
	//FOR(i,1,n)cout<<dep[i]<<" ";
	//cout<<endl;
	
	FOR(j,1,20)
		FOR(i,1,n)
			fa[i][j]=fa[fa[i][j-1]][j-1],
			w[i][j]=min(w[i][j-1],w[fa[i][j-1]][j-1]);
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(find(x)!=find(y))cout<<"-1\n";
		else cout<<lca(x,y)<<endl;
	}
}
