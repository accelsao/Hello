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
const int N=1e5+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
int n,q,s;
struct tree{
	int l,r;
}tr[N*4];
struct edge{
	int to;
	LL w;
};
vector<edge>g[N*20];
LL tot;
struct D{
	LL dis;
	int id;
	bool operator<(const D &a)const{
		return dis>a.dis;
	}
}d[N*20];
int vis[N*20];
void build(int rt,int l,int r){
	if(l==r){
		tr[rt].l=tr[rt].r=l;
		return ;
	}
	tr[rt].l=++tot;
	tr[rt].r=++tot;
	int m=l+r>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	g[tr[rt].l].PB(edge{tr[rt<<1].l,0});
	g[tr[rt].l].PB(edge{tr[rt<<1|1].l,0});
	g[tr[rt<<1].r].PB(edge{tr[rt].r,0});
	g[tr[rt<<1|1].r].PB(edge{tr[rt].r,0});
}
void update(int rt,int l,int r,int u,int L,int R,int w,int t){
	//cout<<l<<" "<<r<<endl;
	if(L<=l&&r<=R){
		if(t==2){
			g[u].PB(edge{tr[rt].l,w});
		}
		else{
			g[tr[rt].r].PB(edge{u,w});
		}
		return ;
	}
	int m=l+r>>1;
	if(L<=m)update(rt<<1,l,m,u,L,R,w,t);
	if(m<R)update(rt<<1|1,m+1,r,u,L,R,w,t);
}
int main(){Accel
	cin>>n>>q>>s;
	tot=n;
	build(1,1,n);
	REP(i,q){
		int t,u,v,l,r,w;
		cin>>t;
		if(t==1){
			cin>>u>>v>>w;
			g[u].PB(edge{v,w});
		}
		else{
			cin>>u>>l>>r>>w;
			update(1,1,n,u,l,r,w,t);
		}
	}
	//dijk();
	priority_queue<D>q;
	FOR(i,0,N*5)d[i].dis=1e18,d[i].id=i;
	d[s].dis=0;
	q.push(d[s]);
	while(q.size()){
		LL dis=q.top().dis;int id=q.top().id;q.pop();
		if(vis[id])continue;
		vis[id]=1;
		for(auto i:g[id]){
			int v=i.to;LL wt=i.w;
			if(d[v].dis>d[id].dis+wt){
				d[v].dis=d[id].dis+wt;
				q.push(d[v]);
			}
		}
	}
	FOR(i,1,n)
		cout<<(d[i].dis==1e18?-1:d[i].dis)<<" ";
}
