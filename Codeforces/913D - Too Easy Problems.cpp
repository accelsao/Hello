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
const int N=2e5+1;
const int M=1e9+7;
int n,T,mt,c[N];
int main(){Accel
	cin>>n>>T;
	vector<vector<PII>>p(n+1);
	int a,t;
	REP(i,n){
		cin>>a>>t;
		p[a].PB({t,i+1});
		mt=max(a,mt);
	}
	set<PII>s;
	int sum=0;
	for(int k=mt;k>=1;k--){
		for(auto x:p[k]){
			sum+=x.F;
			s.emplace(x);
		}
		while((int)s.size()>k){
			auto z=--s.end();
			sum-=z->F;
			s.erase(z);
		}
		if(sum<=T&&(int)s.size()==k){
			cout<<k<<'\n'<<k<<'\n';
			for(auto x:s)
				cout<<x.S<<" ";
			return 0;
		}
	}
	puts("0\n0");
}
// S2
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
const int N=2e5+1;
const int M=1e9+7;
int n,T,ans,c;
struct Pm{int a,t,id;}p[N];
void F(){
	int t=0,s=0,need=ans+c;
	for(int i=0;i<n&&t+p[i].t<=T&&s<need;i++)
		if(p[i].a>=need){
			s++;
			t+=p[i].t;
			if(!c)cout<<p[i].id<<" ";
		}
	if(s==need&&t<=T)ans=need;
}
int main(){Accel
	cin>>n>>T;
	REP(i,n)cin>>p[i].a>>p[i].t,p[i].id=i+1;
	sort(p,p+n,[](Pm &a,Pm &b){return a.t<b.t;});
	for(c=1<<17;c;c/=2)F();
	cout<<ans<<"\n"<<ans<<"\n";
	F();
}
