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
const int M = 998244353 ;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

int n;
ll a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	ll p100 = pw(100, M-2);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=a[i]*p100%M;
	}
	ll ans=0;
	ll pref=1;
	for(int i=0;i<n;i++){
		ans=(ans+pref)%M;
		pref=pref*a[i]%M;
	}
	ans=ans*pw(pref, M-2)%M;
	cout<<ans<<"\n";
	
	// E = (1-p1)(E+1) + p1(1-p2)(E+2) + p1p2(1-p3)(E+3) ... p1p2...(1-pn)(E+n) + p1p2...pn(n)
	// compute E
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/

