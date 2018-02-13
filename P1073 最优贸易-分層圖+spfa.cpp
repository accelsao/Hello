//建三層圖-類似flow原理

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
const int N=100000+10;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
int a[N];
int n,m;
vector<PII>g[N*3+1];
int d[N*3+1],vis[N*3+1];
void add(int x,int y){
	g[x].PB(MP(y,0));
	g[x].PB(MP(y+n,-a[x]));
	g[x+n].PB(MP(y+n,0));
	g[x+n].PB(MP(y+2*n,a[x]));
	g[x+2*n].PB(MP(y+2*n,0));
	return;
}
int main(){Accel
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	REP(i,m){
		int u,v,t;
		cin>>u>>v>>t;
		add(u,v);
		if(t==2)add(v,u);	
	}
	
	g[n].PB(MP(3*n+1,0));
	g[n*3].PB(MP(3*n+1,0));
	//3*n+1 T 匯點 
	n=3*n+1;
	FOR(i,1,n)d[i]=-1e9;
	d[1]=0;
	queue<int>q;
	q.push(1);

	
	while(q.size()){
		int u=q.front();q.pop();
		vis[u]=0;
		//cout<<u<<endl;
		for(auto i:g[u]){
			int v=i.F;
			if(d[v]<d[u]+i.S){
				d[v]=d[u]+i.S;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	
	cout<<d[n]<<endl;
}
