// �i�i�i�������������������������������������������������������������������������i
// �i�i�i���i�i�i�i�i�i�i�������������������������������i�i�i���������i�����������i
// �i�i�i�i�i�i�i���i�i�i�i�i�����������������������i�i�i�������������������������i
// �i�i�i�i���������������i�i�i�i�i������������i�i�i����������������������������i
// �i�i�i�����������������������i�i�����������������������������������������������i
// �i�i�i�i�����������������������i�����������������������������������������������i
// �i�i�i���i���i�i�i�i�i�i�i�����i�i�i�����������������i�i�i�i�i�i�i�������������i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i���i������������������������������������������i
// �i�i�i�����������������������������i�������������������������������������������i
// �i�i�i�i���������������������������i�������������������������������������������i
// �i�i�i���i���������������������������������������������������������������������i
// �i�i�i�i�i�����������������i�������i�������������������������������������������i
// �i�i�i�i�i���������������i�i�������i����������������������������������������i�i
// �i�i�i�i�i�����������i�i�i�i�������i����������������������������������������i�i
// �i�i�i�i���i���������i�i���������i�i����������������������������������������i�i
// �i�i�i�i�����i�i�i���������������i�i��������������������������i�������������i�i
// �i�i�i�i�i���i�i�i�����������������i�i�i�i������������������i���������������i�i
// �i�i�i�i�i�����i���i�i�i�������i�i�i�i�����i���������������i��������������i�i�i
// �i�i�i�i�i�i���i�i���i�i�i�i�i�i�i�������������������i�i�������������������i�i�i
// �i�i�i�i�i�i�i���i�i����������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�����i�i���������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�i�������i�i�i�i�i���������������������������������������i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�������i�����������i�i�i���������������������������i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�������i�����������i�i�������������������������i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�����i���������i�i�i�����������������������i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�i��������������������i�i�i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�������������������i�i�i�i�i�i�i�i�i�i�i
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

int n, m;
vector<int> g[N];
int vis[N], low[N], ins[N], belong[N], dfn, scc;

stack<int> s;
void tarjan(int u){
	vis[u]=low[u]=++dfn;
	ins[u]=1;
	s.push(u);
	for(const int& v:g[u]){
		if(!vis[v]){
			tarjan(v);
			low[u]=min(low[u], low[v]);
		}
		else if(ins[v]){
			low[u]=min(low[u], vis[v]);
		}
	}
	if(low[u]==vis[u]){
		int p;
		++scc;
		do{
			p=s.top();s.pop();
			ins[p]=0;
			belong[p]=scc;
		}while(u!=p);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			g[i].clear();
			vis[i]=low[i]=ins[i]=belong[i]=0;
			dfn=scc=0;
		}

		while(s.size())s.pop();
		int u, v;
		for(int i=0;i<m;i++){
			cin>>u>>v;
			if(u!=v){
				g[u].PB(v);
			}
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				tarjan(i);
			}
		}

		if(scc==1){
			puts("No");
		}
		else{
			vector<int> a, b;
			for(int i=1;i<=n;i++){
				if(belong[i]==1){
					a.push_back(i);
				}
				else{
					b.push_back(i);
				}
			}
			puts("Yes");
			printf("%d %d\n", SZ(a), SZ(b));
			for(const int& x:a){
				printf("%d ", x);
			}
			puts("");
			for(const int& x:b){
				printf("%d ", x);
			}
			puts("");
		}
	}
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/



