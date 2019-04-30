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
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
LL a,b,p,x;
LL A[N]={1};
int main(){Accel
	cin>>a>>b>>p>>x;
	LL ans=0;
	FOR(i,1,p-1)A[i]=A[i-1]*a%p;
	FOR(j,1,p-1){
		LL y=b*A[p-1-j]%p;
		LL i=(j-y+p)%p;
		LL tmp=i*(p-1)+j;
		if(x>=tmp){
			ans+=(x-tmp)/p/(p-1)+1;
		}
	}
	cout<<ans<<endl;
}
