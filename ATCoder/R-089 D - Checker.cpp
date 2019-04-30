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
const int N=1e5+5;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,k;
int x[N],y[N];
char c[N];
int cnt[1005*2],ans;
int main(){Accel
	cin>>n>>k;
	int K=k*2;
	REP(i,n){
		int a,b;
		cin>>a>>b>>c[i];
		x[i]=a%K;
		y[i]=b%K;
	}
	REP(i,K){
		Re(cnt,0);
		int r=0;
		REP(j,n){
			//int a=(x[j]-i+K)%K;
			//a=(a<k);
			int a=((x[j]-i<0?x[j]-i+K:x[j]-i)<k);
			if(a^(y[j]<k))r+=c[j]=='B';
			else r+=c[j]=='W';
			cnt[y[j]]+=(a^(c[j]=='W'))?1:-1;
		}
		REP(j,K){
			ans=max(ans,r);
			r+=cnt[j]-cnt[(j+k)%K];
		}
		
	}
	cout<<ans<<endl;
}
