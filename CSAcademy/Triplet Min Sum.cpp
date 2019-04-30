// RMQ DFS序 LCA
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
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=1e5+1;
const int M=1e9+7;
int n,q;
vector<int>g[N];
int dis[N],df[N*2],cnt,pos[N],lg[N*2],rmq[N*2][30];

void dfs(int u,int p){
    pos[u]=++cnt;
    df[cnt]=u;
    dis[u]=dis[p]+1;
    for(auto v:g[u])
        if(v-p){
            dfs(v,u);
            df[++cnt]=u;
		}
}
int lca(int x,int y){
	if(pos[x]>pos[y])swap(x,y);
	int j=0;
	while((1<<(j+1))<=pos[y]-pos[x]+1)j++;
	int l=rmq[pos[x]][j];
	int r=rmq[pos[y]-(1<<j)+1][j];
	return dis[l]<dis[r]?l:r;
}
int d(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
int main(){Accel
    cin>>n>>q;
    int u,v;
    REP(i,n-1){cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
	FOR(i,2,cnt)lg[i]=lg[i/2]+1;
	FOR(i,1,cnt)rmq[i][0]=df[i];
	for(int j=1;(1<<j)<=cnt;j++)
	for(int i=1;i+(1<<j)-1<=cnt;i++){
		int x=rmq[i][j-1];
		int y=rmq[i+(1<<(j-1))][j-1];
		rmq[i][j]=dis[x]<dis[y]?x:y;
	}
    int a,b,c;
    while(q--){
        cin>>a>>b>>c;
        int ans,D;
        int nd=lca(a,b),len;
        D=nd;
        ans=d(nd,a)+d(nd,b)+d(nd,c);
        nd=lca(a,c);
        len=d(nd,a)+d(nd,b)+d(nd,c);
        if(len<ans)
			ans=len,D=nd;
        nd=lca(b,c);
        len=d(nd,a)+d(nd,b)+d(nd,c);
        if(len<ans)
			ans=len,D=nd;
        cout<<D<<" "<<ans<<endl;
    }
}
// 倍增LCA
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
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=1e5+1;
const int M=1e9+7;
int n,q;
vector<int>g[N];
int dis[N],df[N*2],cnt,pos[N],lg[N*2],rmq[N*2][30];
int fa[N][20];
void dfs(int u,int p){
    dis[u]=dis[p]+1;
    fa[u][0]=p;
    for(auto v:g[u])
        if(v-p)
            dfs(v,u);
}
int lca(int x,int y){
	if(dis[x]<dis[y])swap(x,y);
	for(int j=19;~j;j--)
		if(dis[fa[x][j]]>=dis[y])x=fa[x][j];
	if(x==y)return x;
	for(int j=19;~j;j--)
		if(fa[x][j]!=fa[y][j])
			x=fa[x][j],y=fa[y][j];
	return fa[x][0];
}
int d(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
int main(){Accel
    cin>>n>>q;
    int u,v;
    REP(i,n-1){cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    FOR(j,1,19)
    	FOR(i,1,n)
    		fa[i][j]=fa[fa[i][j-1]][j-1];
    //dis[0]=-1;
    int a,b,c;
    while(q--){
        cin>>a>>b>>c;
        int ans,D;
        int nd=lca(a,b),len;
        D=nd;
        ans=d(nd,a)+d(nd,b)+d(nd,c);
        nd=lca(a,c);
        len=d(nd,a)+d(nd,b)+d(nd,c);
        if(len<ans)
			ans=len,D=nd;
        nd=lca(b,c);
        len=d(nd,a)+d(nd,b)+d(nd,c);
        if(len<ans)
			ans=len,D=nd;
        cout<<D<<" "<<ans<<endl;
    }
}
