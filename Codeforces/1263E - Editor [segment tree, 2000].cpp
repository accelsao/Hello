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


struct Node{
	int mx, mn, sum;
};
Node tr[N+N];

void pull(int u){
	tr[u].sum=tr[u+u].sum+tr[u+u+1].sum;
	tr[u].mx=max(tr[u+u].mx, tr[u+u].sum + tr[u+u+1].mx);
	tr[u].mn=min(tr[u+u].mn, tr[u+u].sum + tr[u+u+1].mn);
}

void update(int p, int v){
	p+=N;
	tr[p].sum=v;
	tr[p].mx=max(v, 0);
	tr[p].mn=min(v, 0);
	while(p>>=1){
		pull(p);
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<n;i++){
		
		if(s[i]=='L'){
			j=max(0, j-1);
		}
		else if(s[i]=='R'){
			j++;
		}
		else if(s[i]==')'){
			update(j, -1);
		}
		else if(s[i]=='('){
			update(j, 1);
		}
		else{
			update(j, 0);
		}
		
		if(tr[1].sum==0&&tr[1].mn>=0){
			cout<<tr[1].mx<<" ";
		}
		else{
			cout<<"-1 ";
		}
	}
	
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/



