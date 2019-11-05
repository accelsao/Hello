#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
const int N = 1e6 +10;
const int M = 1e9 + 123;
const int inf = 1e9+7;
const ll INF = 1e18;

int gen_base(int l, int r){
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 mt_rand(seed);
	int base = uniform_int_distribution<int>(l+1, r)(mt_rand);
	return (base&1) ? base: base-1;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int base = gen_base(256, M);
	string p, s;
	for(int i=0;i<n;i++){
		cin>>s;
		int len=min(s.size(), p.size());
		pair<ll, ull> h1, h2;
		h1=h2={0, 0};
		int from=0, pl=p.size();
		ll bs1 = 1;
		ull bs2 = 1;
		for(int j=0;j<len;j++){
			h1.F = (h1.F * base + s[j]) % M;
			h2.F = (h2.F + bs1 * p[pl-1-j]) % M;
			
			h1.S = h1.S * base + s[j];
			h2.S = h2.S + bs2 * p[pl-1-j];
			bs1 = bs1 * base % M;
			bs2 = bs2 * base;

			if(h1 == h2){
				from=j+1;
			}
		}
		p+=s.substr(from);
	}
	
	cout<<p<<"\n";
}
/*
3
I I5 I59
*/
