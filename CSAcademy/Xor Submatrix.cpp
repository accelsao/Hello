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
const int N=1e3+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int ans;
int trie[N*N*30][2],sz=1;
void in(int x){
	int p=1,s;
	for(int i=30;~i;i--){
		s=x>>i&1;
		if(!trie[p][s])trie[p][s]=++sz;
		p=trie[p][s];
	}
}
int find(int x){
	int p=1,s,ans=0;
	for(int i=30;~i;i--){
		s=x>>i&1;
		if(trie[p][s^1])p=trie[p][s^1],ans+=1<<i;
		else p=trie[p][s];
	}
	return ans;
}
int main(){Accel
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),b(m+1);
	FOR(i,1,n)cin>>a[i],a[i]^=a[i-1];
	FOR(i,1,m)cin>>b[i],b[i]^=b[i-1];
	int mx=0;
	FOR(i,1,n)FOR(j,i,n){
		if((j-i+1)&1)in(a[i-1]^a[j]);
		else ans=max(ans,a[i-1]^a[j]);
	}
	FOR(i,1,m)FOR(j,i,m)
		if((j-i+1)&1)ans=max(ans,find(b[i-1]^b[j]));
		else ans=max(ans,b[i-1]^b[j]);
	cout<<ans<<endl;
}
