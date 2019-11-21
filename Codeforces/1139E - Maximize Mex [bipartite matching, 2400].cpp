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
//#define DEBUG
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
const int N = 5678;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}


int n, m, d;
int p[N];
int c[N];
int b[N];
bool stay[N];
vector<int> g[N];
int match[N], ans[N];
int vis[N];
int df;

bool dfs(int u){
	if(vis[u]==df)return 0;
	vis[u]=df;
	for(const int& v:g[u]){
		if(match[v]==-1 || dfs(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>p[i];
		stay[i]=1;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	cin>>d;
	for(int i=0;i<d;i++){
		cin>>b[i];
		stay[b[i]-1]=0;
	}
	
	RE(match, -1);
	df=1;

	for(int i=0;i<n;i++){
		if(stay[i]){
			g[p[i]].PB(c[i]);
		}
	}
	int ls=0;
	for(int i=d-1;~i;i--){
		++df;
		while(dfs(ls)){
			df++;
			ls++;
		}
		ans[i]=ls;
		int u=b[i]-1;
		g[p[u]].PB(c[u]);
	}
	for(int i=0;i<d;i++){
		printf("%d\n", ans[i]);
	}
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif


1 = {0} 
2 = {0, 1, 2}
3 = {2}  

1 = {0} 
2 = {0, 1}
3 = {2}

1 = {0} 
2 = {0}
3 = {2}
*/

