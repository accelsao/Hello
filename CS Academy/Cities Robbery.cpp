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
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,x,k;
int main(){Accel
	cin>>n>>x>>k;
	vector<PII>p(n);
	REP(i,n)cin>>p[i].F>>p[i].S;
	LL ans=0,t=0,id=-1;
	int r=n-1;
	REP(i,n)
		if(p[i].F>x){
			if(id==-1)id=i;
			if(p[i].F>x+k){
				r=i-1;
				break;
			}
			t+=p[i].S;
		}
	ans=max(ans,t);
	//cout<<id<<endl;
	for(int i=id-1;i>=0;i--){
		LL d;
		if(p[r].F-x>x-p[i].F)
			d=p[r].F-x+(x-p[i].F)*2;
		else d=(p[r].F-x)*2+x-p[i].F;
		t+=p[i].S;
		while(d>k&&r>id){
			t-=p[r--].S;
			if(p[r].F-x>x-p[i].F)
				d=p[r].F-x+(x-p[i].F)*2;
			else d=(p[r].F-x)*2+x-p[i].F;
			//cout<<d<<" "<<k;
		}
		if(d<=k)ans=max(ans,t);
	}
	//cout<<ans<<endl;
	t=0;
	for(int i=n-1;i>=0;i--){
		if(p[i].F<x){
			if(p[i].F+k<x)break;
			t+=p[i].S;
		}
	}
	ans=max(ans,t);
	cout<<ans<<endl;
}
