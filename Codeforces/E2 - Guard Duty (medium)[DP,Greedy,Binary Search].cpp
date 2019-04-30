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
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int n,k;
LL a[N];
struct A{
	LL v;int p;
	bool operator<(const A &h)const{return v>h.v;}
};
int l[N],r[N],vis[N];
void del(int x){
	l[r[x]]=l[x];
	r[l[x]]=r[x];
	vis[x]=1;
}
priority_queue<A>q;
int main(){Accel
	cin>>k>>n;
	FOR(i,1,n)
		cin>>a[i];
	sort(a+1,a+1+n);
	FOR(i,1,n-1){
		a[i]=a[i+1]-a[i];
		q.push(A{a[i],i});
		l[i]=i-1,r[i]=i+1;
		//vis[i]=1;
	}
	a[0]=a[n]=1e18;
	LL ans=0;
	while(k--){
		while(vis[q.top().p])q.pop();
		//cout<<q.top().v<<endl;
		int p=q.top().p;
		ans+=a[p];
		q.pop();
		a[p]=a[r[p]]+a[l[p]]-a[p];
		del(r[p]),del(l[p]);
		q.push(A{a[p],p});
		//cout<<k<<endl;
	}
	cout<<ans<<endl;
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
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=5e5+10;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const LL inf=1e18;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int n,m,cnt;
int a[N];
int dp[2][2][5005];
PII q[N];
bool vis[N];
int main(){
	scanf("%d%d",&m,&n);
	FOR(i,1,n)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if (n<=30000){
		Re(dp,127);

		dp[0][0][0] = dp[1][0][0] = 0; 
		FOR(i,2,n){
			for(int j=min(m,i/2);j>=1;j--){
			//FOR(j,1,min(m,i/2)){
				dp[cnt][0][j] = min(dp[cnt^1][0][j],dp[cnt^1][1][j]);
				dp[cnt][1][j] = dp[cnt^1][0][j-1]+a[i]-a[i-1];
			//}
			}
			cnt^=1;
		}
		printf("%d\n",min(dp[cnt^1][0][m],dp[cnt^1][1][m]));
	}
	else{
		FOR(i,1,n-1) q[i] = MP(a[i+1]-a[i],i);
		sort(q+1,q+n);
		int sum=0;
		for(int i=1;m;i++){
			if (!vis[ q[i].second+1 ] && !vis[ q[i].second-1 ]){
				vis[ q[i].second ] = 1;
				sum += q[i].first;
				m--;
			}
		}
		printf("%d",sum);
	}
}
//#include <bits/stdc++.h>
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
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=500000+10;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const LL inf=1e18;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int k,n;
int a[N];
pair<LL,int> f[N];
pair<LL,int> judge(int cost){
	FOR(i,2,n){
		f[i]=min(f[i-1],MP(f[i-2].F-cost+a[i]-a[i-1],f[i-2].S+1));
	}
	return f[n];
}
int main(){Accel
	cin>>k>>n;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=1e9,m;
	pair<LL,int> t;
	while(l<=r){
		m=(l+r)>>1;
		t=judge(m);
		if(t.S>k)r=m-1;
		else l=m+1;
	}
	t=judge(l-1);
	cout<<t.F+1LL*(l-1)*k<<endl;
	
}
