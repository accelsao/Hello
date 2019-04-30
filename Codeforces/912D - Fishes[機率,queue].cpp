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
const int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,r,k;
LL scoop(int x,int y){return (min(n+1,x+r)-max(x,r))*(min(m+1,y+r)-max(y,r));}
priority_queue<pair<LL,PII>>q;
map<PII,int>vis;

int main(){Accel
	cin>>n>>m>>r>>k;
	int h=(n+1)/2,g=(m+1)/2,th,tg;
	q.push({scoop(h,g),{h,g}});
	vis[{h,g}]=1;
	double ans=0;
	while(k--){
		h=q.top().S.F,g=q.top().S.S;
		ans+=scoop(h,g);q.pop();
		for(int d=0;d<4;d++){
			th=h+dw[d][0],tg=g+dw[d][1];
			if(!vis[{th,tg}]){
				q.push({scoop(th,tg),{th,tg}});
				vis[{th,tg}]=1;
			}
		}
	}
	printf("%.9lf\n",ans/(n-r+1)/(m-r+1));
}
