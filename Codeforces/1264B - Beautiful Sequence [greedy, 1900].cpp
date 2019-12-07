#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define RE(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define SZ(x) ((int)(x.size()))
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using C = complex<double>;
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}


int ans[N];
int cnt[N];
int n;
void dfs(int u, int ls=-1){
	if(u==n){
		cout<<"YES\n";
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		exit(0);
	}
	
	if(ls==-1){
		for(int i=0;i<4;i++){
			if(cnt[i]){
				ans[u]=i;
				cnt[i]--;
				dfs(u+1, i);
				cnt[i]++;	
			}

		}
	}
	else{
		int nxt=-1;
		if(ls==0)nxt=1;
		if(ls==1){
			if(cnt[0])nxt=0;
			else nxt=2;
		}
		if(ls==2){
			if(cnt[1])nxt=1;
			else nxt=3;
		}
		if(ls==3){
			nxt=2;
		}
		if(cnt[nxt]<=0)return ;
		ans[u]=nxt;
		cnt[nxt]--;
		dfs(u+1, nxt);
		cnt[nxt]++;
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	n=0;
	for(int i=0;i<4;i++){
		cin>>cnt[i];
		n+=cnt[i];
	}
	dfs(0);
	cout<<"NO\n";
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif

10000 100 100 100

*/

