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
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n;
LL ans=1LL<<60,x,y;
int pr[N],a[N],s[N],mx;
map<int,int>mp;
int main(){Accel
	cin>>n>>x>>y;
	REP(i,n)
		cin>>a[i],s[a[i]]++,mx=max(mx,a[i]);
	int t=x/y;
	t=min(mx+t+1,N-1);
	FOR(i,2,t)
		if(!pr[i]){
			int tmp=s[i];
			for(int k=i*2;k<=t;k+=i){
				pr[k]=1;
				tmp+=s[k];
			}
			if((n-tmp)*min(x,y)>=ans)continue;
			LL val=0;
			REP(j,n)
				if(a[j]%i)
					val+=min(x,(i-(a[j]%i))*y);
			ans=min(val,ans);
		}
	cout<<ans<<endl;
}
