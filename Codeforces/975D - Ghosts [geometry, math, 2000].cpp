#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
 
map<ll, int> p1;
map<pair<int,int>, int> p2;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	ll a, b;
	cin>>n>>a>>b;
	ll x, y, p;
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>p>>x>>y;
		ll s=a*x-y;
		ans+=p1[s]-p2[{x, y}];
		p2[{x, y}]++;
		p1[s]++;
	}
	cout<<ans*2<<"\n";
}
