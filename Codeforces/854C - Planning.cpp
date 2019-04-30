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
const int N=3e5+1;
const int K=200;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,k,x;
int ans[N];
int main(){Accel
	cin>>n>>k;
	set<PLL>s;
	LL tot=0;
	FOR(i,1,n+k){
		if(i<=n){
			cin>>x;
			s.insert({x,i});
		}
		if(i<=k)continue;
		auto it=s.rbegin();
		ans[it->S]=i;
		tot+=(i-it->S)*it->F;
		s.erase(*it);
	}
	cout<<tot<<endl;
	FOR(i,1,n)cout<<ans[i]<<" ";
}
