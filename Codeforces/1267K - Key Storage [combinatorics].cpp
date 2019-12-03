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
//using C = complex<double>;
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 1e2 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

int C[N][N];
int cnt[N];
ll find(int n){
	int pos=0;
	for(int i=n+1;i<N;i++)
		if(cnt[i])return 0;
	ll ans=1;
	for(int i=n;i>=1;i--){
		++pos;
		if(pos<cnt[i])return 0;
		ans*=C[pos][cnt[i]];
		pos-=cnt[i];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	for(int i=1;i<N;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	
	int T;
	cin>>T;
	ll k;
	while(T--){
		cin>>k;
		RE(cnt, 0);
		int n=0;
		for(int i=2;k;i++){
			cnt[k%i]++;
			k/=i;
			++n;
		}
		ll ans=find(n);
		if(cnt[0]){
			ans-=find(n-1); //minus last one is zero (invalid, because once zero occurs, sequence stop)
		}
		cout<<ans-1<<"\n"; //minus itself
		
	}
	
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/

