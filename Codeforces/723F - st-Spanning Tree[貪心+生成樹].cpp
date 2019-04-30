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
#define endl "\n"
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
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
int n,m;
vector<int>g[N],S[N],T[N];
int s,t,ds,dt;
bool vis[N];
int cnt=0;
vector<PII>ans;
void dfs(int u){
	vis[u]=1;
	for(auto v:g[u]){
		if(v==s){
			S[cnt].PB(u);
		}
		else if(v==t)
			T[cnt].PB(u);
		else if(!vis[v]){
			dfs(v);
			ans.PB(MP(u,v));
		}
	}
}
int main(){Accel
	cin>>n>>m;
	FOR(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	}
	cin>>s>>t>>ds>>dt;
	FOR(i,1,n)
		if(!vis[i]&&i!=s&&i!=t)
			dfs(i),cnt++;
	int com=0;
	REP(i,cnt){
		if(!SZ(S[i])){
			ans.PB(MP(T[i][0],t));
			dt--;
		} 
		else if(!SZ(T[i])){
			ans.PB(MP(S[i][0],s));
			ds--;
		}
		else com++;
	}
	if(dt<1||ds<1||dt+ds<com+1){
		cout<<"No\n";return 0;
	}
	if(!com)ans.PB(MP(s,t));
	else{
		for(int i=0,f=0;i<cnt;i++){
			if(SZ(S[i])&&SZ(T[i])){
				if(f){
					if(ds)ans.PB(MP(S[i][0],s)),ds--;
					else ans.PB(MP(T[i][0],t)),dt--;
				}
				else{
					f=1;
					ans.PB(MP(S[i][0],s)),ds--;
					ans.PB(MP(T[i][0],t)),dt--;
				}
			}
		}
	}
	cout<<"Yes\n";
	for(auto x:ans)
		cout<<x.F<<" "<<x.S<<endl;
}
