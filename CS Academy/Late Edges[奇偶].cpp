

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
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int n,m;
struct A{
    int to,d;
};
int f[N];
vector<A>g[N];
int dis[N][2];
const int inf=1e9+1e8+1e7;
int main(){Accel
    cin>>n>>m;
    FOR(i,1,n)FOR(j,0,1)dis[i][j]=inf;
    
    REP(i,m){
        int u,v,d;
        cin>>u>>v>>d;
        g[u].PB(A{v,d});
        g[v].PB(A{u,d});
        
    }
    dis[1][0]=0;
    priority_queue<PII>q;
    q.push(MP(1,0));
    while(q.size()){
        int u=q.top().F;
        int d=-q.top().S;
        q.pop();
        for(auto i:g[u]){
            int v=i.to;
            int nxt;
            if(i.d<=d){
                nxt=d+1;
            }
            else{
                nxt=i.d+1;
                //if 相差非偶 +1
                if(i.d&1^d&1)nxt++;
                
            }
            if(nxt<dis[v][nxt&1]){
                dis[v][nxt&1]=nxt;
                q.push(MP(v,-nxt));
            }
        }
    }
    int mn=min(dis[n][0],dis[n][1]);
    if(mn==inf)cout<<-1<<endl;
    else cout<<mn<<endl;
}
