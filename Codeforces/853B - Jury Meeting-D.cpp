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
const int N=1e5+1;
const LL M=1e12;
const double eps=1e-6;
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,m,k;
struct trip{
	int d,a;
	LL c;
};
bool cmp(trip a,trip b){
	if(a.d==b.d)return a.c<b.c;
	return a.d<b.d;
}
int main(){Accel
	cin>>n>>m>>k;
	vector<trip>s,t;
	int d,a,b;
	LL c;
	REP(i,m){
		cin>>d>>a>>b>>c;
		if(a)
			s.PB(trip{d,a,c});
		else
			t.PB(trip{-d,b,c});
	}
	vector<trip>G,T;//Go To
	LL ans=M;
	vector<LL>cost(n+1,M);
	LL best=n*M;
	sort(ALL(s),cmp);
	for(auto x:s){
		d=x.d;a=x.a;c=x.c;
		if(c<cost[a]){
			best+=c-cost[a];
			cost[a]=c;
			if(best<ans)G.PB({d,0,best});
		}
	}
	ans=M;
	for(auto &it:cost)it=M;
	best=n*M;
	sort(ALL(t),cmp);
	for(auto x:t){
		d=x.d;a=x.a;c=x.c;
		if(c<cost[a]){
			best+=c-cost[a];
			cost[a]=c;
			if(best<ans)T.PB({d,0,best});
		}
	}
	ans=M;
	for(auto g:G){
		for(auto t:T){
			//cout<<t.d<<endl;
			if(g.d+t.d+k<0)ans=min(ans,(LL)g.c+t.c);
			else break;
		}
	}
	if(ans<M)cout<<ans<<endl;
	else cout<<"-1\n";
}
