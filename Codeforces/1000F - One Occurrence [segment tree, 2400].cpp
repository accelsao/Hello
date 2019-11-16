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
const int N = 1<<20;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

int n, q;
int a[N];
pii seg[N<<1];
vector<pii> query[N];
int ans[N];
int ls[N];

void modify(int p, int val){
	p+=N;
	seg[p].F=val;
	while(p){
		p>>=1;
		seg[p]=min(seg[p+p], seg[p+p+1]);
	}
}

pii find(int l, int r){
	pii ans={N, N};
	for(l+=N, r+=N; l<r; l>>=1, r>>=1){
		if(l&1){
			ans=min(ans, seg[l++]);
		}
		if(r&1){
			ans=min(ans, seg[--r]);
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	
	for(int i=0;i<N;i++){
		seg[i+N]={N, N};
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		seg[i+N].S=a[i];
	}
	for(int i=N-1;i;i--){
		seg[i]=min(seg[i+i], seg[i+i+1]);
	}
	
	
	cin >> q;
	int l, r;
	for(int i=0;i<q;i++){
		cin>>l>>r;r--;l--;
		query[r].PB({l, i});
	}
	RE(ls, -1);
	for(int i=0;i<n;i++){
		if(~ls[a[i]]){
			modify(ls[a[i]], N);
		}
		modify(i, ls[a[i]]);
		ls[a[i]]=i;
		for(const pii& q: query[i]){
			pii res = find(q.F, i+1);
			if(res.F >= q.F){
				ans[q.S] = 0;
			}
			else{
				ans[q.S] = res.S;
			}
		}
	}
	for(int i=0;i<q;i++){
		printf("%d\n", ans[i]);
	}
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/



