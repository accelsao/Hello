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

#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=1e5+1;
const int M=1e9+7;
int n,t,vis[N],u,v,p[N];
vector<int>g[N];
vector<int>color[2];
void dfs(int u,int t){
    color[t].PB(u);
    vis[u]=0;
    for(auto v:g[u])
        if(vis[v])
            dfs(v,t^1);
}
set<PII>s;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        FOR(i,1,n)g[i].clear(),vis[i]=1;
        s.clear();
        REP(i,n-1){
            cin>>u>>v;
            g[u].PB(v);
            g[v].PB(u);
            s.insert({u,v});
            s.insert({v,u});
        }
        color[0].clear(),color[1].clear();
        dfs(1,0);
        if(color[0].size()==1||color[1].size()==1)puts("-1");
        else{
            int f=0,u,v;
            for(auto x:color[0]){
                for(auto y:color[1]){
                    if(s.find({x,y})==s.end())
                        f=1,u=x,v=y;
                    if(f)break;
                }
                if(f)break;
            }
            for(auto x:color[0])if(x!=u)cout<<x<<" ";
            cout<<u<<" "<<v<<" ";
            for(auto x:color[1])if(x!=v)cout<<x<<" ";
        }
    }
}
