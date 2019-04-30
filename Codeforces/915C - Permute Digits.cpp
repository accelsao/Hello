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
const int N=1e5+1;
const int M=1e9+7;
string a,b;
int c[10],n,ans[20];
void dfs(int i,int bnd){
	if(i==n){
			REP(i,n)
			cout<<ans[i];
			cout<<endl;
			exit(0);
		}
	int k=bnd?b[i]-'0':9;
	//cout<<k<<endl;
	for(int j=k;~j;j--)
		if(c[j]){
			ans[i]=j;
			c[j]--;
			dfs(i+1,j==k&&bnd);
			c[j]++;
		}
}
int main(){Accel
	while(cin>>a>>b){
		if(a.size()<b.size()){
			for(auto x:a)c[x-'0']++;
			for(int i=9;~i;i--)while(c[i])cout<<char(i+'0'),c[i]--;
			cout<<endl;
		}
		else{
			for(auto x:a)c[x-'0']++;
			n=a.size();
			dfs(0,1);
		}
	}
}
