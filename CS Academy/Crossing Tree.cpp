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
const int N=1e5+10;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n;
vector<int>g[N];
int dep[N];
void dfs(int u,int d=0,int p=0){
    dep[u]=d;
    for(auto v:g[u])
        if(v-p)dfs(v,d+1,u);
}
void dfs_all(int u,int p){
    cout<<u<<" ";
    for(auto v:g[u])
        if(v!=p){
            dfs_all(v,u);
            cout<<u<<" ";
        }
}
bool dfs_print(int u,int to,int p=0){
    //cout<<u<<endl;
    for(auto v:g[u])
        if(v-p){
            if(!dfs_print(v,to,u))continue;
            cout<<u<<" ";
            for(auto b:g[u]){
                
                //cout<<b<<"<-"<<u<<endl;
                if(b!=p&&b!=v){
                    //cout<<b<<endl;
                    dfs_all(b,u);
                    cout<<u<<" ";
                }
                
            }
            return 1;
        }
    if(u==to)cout<<u<<" ";
    return u==to;
}
int main(){Accel
    cin>>n;
    int u,v;
    REP(i,n-1){
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
        //for(auto v:g[3])cout<<v<<" ";
        //cout<<endl;
    }
    //for(auto v:g[3])cout<<v<<" ";
    //cout<<endl;
    dfs(1);
    int rt=1;
    FOR(i,2,n)
        if(dep[i]>dep[rt])rt=i;
    dfs(rt);
    int ed=1;
    FOR(i,2,n)
        if(dep[i]>dep[ed])ed=i;
    cout<<n*2-2-dep[ed]<<endl;
    //cout<<rt<<" "<<ed<<endl;
    dfs_print(rt,ed);
}
