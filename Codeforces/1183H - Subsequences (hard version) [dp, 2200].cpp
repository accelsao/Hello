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
const int N = 100 + 10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

int n;
ll k;
ll dp[N];
ll tmp[N];
ll f[N];
int lst[N][26];
ll cnt[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	string s;
	cin>>s;
	RE(lst, -1);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			lst[i][s[j]-'a']=j;
		}
	}
	cnt[n]++;
	for(int i=0;i<n;i++){
		dp[i]=1;
		tmp[s[i]-'a']=1;
	}
	for(int i=0;i<26;i++){
		cnt[n-1]+=tmp[i];
		tmp[i]=0;
	}
	
	for(int l=2;l<=n;l++){
		for(int i=0;i<n;i++){
			f[i]=dp[i];
			dp[i]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<26;j++){
				if(~lst[i][j]){
					dp[i]=min(dp[i]+f[lst[i][j]], k);
				}
			}
			tmp[s[i]-'a']=dp[i];
		}
		for(int i=0;i<26;i++){
			cnt[n-l]+=tmp[i];
			tmp[i]=0;
		}
	} 
	#ifdef DEBUG
		for(int i=0;i<=n;i++){
			cout<<cnt[i]<<endl;
		}
	#endif
	ll ans=0;
	for(int i=0;i<=n;i++)
		if(k>cnt[i]){
			k-=cnt[i];
			ans+=cnt[i]*i;
		}
		else{
			ans+=k*i;
			printf("%lld\n", ans);
			return 0;
		}
	puts("-1");
	return 0;
	
}

/*
5 6
aaaaa


#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/


