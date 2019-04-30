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
const int N=55;
const int M=1e9+7;
const double eps=1e-6;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
int n,t1,t2;
int l,r,p,d;
int main(){Accel
	cin>>n>>l>>r;
	cin>>t1>>t2;
	cin>>p>>d;

	
	if(l>r){
		l=n-l,r=n-r;
		p=n-p;
		d=-d;
	}
	int ans=(r-l)*t2;
	int t;
	if(d==-1)t=p+l;
	else if(p<=l)t=l-p;
	else t=n*2-(p-l);
	ans=min(ans,(t+r-l)*t1);
	cout<<ans<<endl;
}
