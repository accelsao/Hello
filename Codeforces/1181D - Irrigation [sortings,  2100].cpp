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
const int N = 1<<20;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

int n, m, q;
ll a[N];
ll b[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	ll x;
	for(int i=1;i<=n;i++){
		cin>>x;
		b[i]=a[x]*m+x;
		a[x]++;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		b[i]-=i;
	}
	while(q--){
		cin>>x;x-=n;
		x+=lower_bound(b+1, b+n+1, x) - (b+1);
		cout<<(x-1) %m+1<<"\n";
	}
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/



