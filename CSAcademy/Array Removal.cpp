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
int n;
int a[N],q[N],l[N],r[N];
LL ans[N],mx,t,s[N];
int main(){Accel
    cin>>n;
    FOR(i,1,n)cin>>a[i];
    REP(i,n)cin>>q[i];
    FOR(i,1,n)
		s[i]=s[i-1]+a[i],
		l[i]=i-1,r[i]=i+1;
    for(int i=n-1;~i;i--){
		int k=q[i];
		mx=max(mx,s[r[k]-1]-s[l[k]]);
		ans[i]=mx;
		r[l[k]]=r[k];
		l[r[k]]=l[k];
	}
    REP(i,n)cout<<ans[i]<<endl;
}

//
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
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n;
int q[N],p[N],f[N];
LL ans[N],mx,s[N];
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
void st(int a,int b){
	a=find(a);b=find(b);
	if(a-b)s[a]+=s[b];
	p[b]=a;
}
int main(){Accel
    cin>>n;
    FOR(i,1,n)cin>>s[i],p[i]=i;
    REP(i,n)cin>>q[i];
    for(int i=n-1;~i;i--){
		int k=q[i];
		mx=max(mx,s[k]);
		f[k]=1;
		if(f[k-1])st(k,k-1);
		if(f[k+1])st(k,k+1);
		mx=max(mx,s[find(k)]);
		ans[i]=mx;
	}
    REP(i,n)cout<<ans[i]<<endl;
}
