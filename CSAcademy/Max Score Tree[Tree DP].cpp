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
const int N=1e5+1;
const LL M=1e18;
int n,u,v,vis[N];
LL ans,c[N];
vector<int>g[N];
LL dfs(int u){
    priority_queue<LL>q;
    vis[u]=1;
    for(auto v:g[u])
        if(!vis[v])
            q.push(dfs(v));
    LL now=0,s=c[1],sz=0;
    while(q.size()){
        now+=q.top();q.pop();
        sz++;
        s=max(s,now+c[sz+1]);
        ans=max(ans,now+c[sz]);
    }
    return s;
}
int main(){Accel
    cin>>n;
    REP(i,n)cin>>c[i];
    REP(i,n-1){
        cin>>u>>v;
        g[u].PB(v);g[v].PB(u);
    }
    ans=c[0];
    dfs(1);
    cout<<ans<<endl;
}
