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
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}


class dsu {
public:
    vector<int> p;
    vector<int> rk;
    int n;
    dsu(int _n) : n(_n){
        p.resize(n);
        rk.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(rk.begin(), rk.end(), 1);
    }
    inline int get(int x){
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    inline bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x != y){
            if(rk[x] >= rk[y]){
                p[y] = x;
                rk[x] += rk[y];
                rk[y] = 0;
            }
            else{
                p[x] = y;
                rk[y] += rk[x];
                rk[x] = 0;
            }

            return true;
        }
        return false;
    }
};



int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	int u, v, c;
	cin >> n;
	dsu d0(n), d1(n);
#ifdef DEBUG
	for(int i=0;i<n;i++){
        cout << d0.p[i] << "\n";
	}
#endif
	for(int i=1;i<n;i++){
        cin >> u >> v >> c;
        u--, v--;
        if(c){
            d1.unite(u, v);
        }
        else{
            d0.unite(u, v);
        }
	}
	ll ans = 0;
	for(int i=0;i<n;i++){

        if(d0.get(i)==i){
            ans += (ll) d0.rk[i] * (d0.rk[i] - 1);
        }
        if(d1.get(i)==i){
            ans += (ll) d1.rk[i] * (d1.rk[i] - 1);
        }

        ans += (ll) (d0.rk[d0.get(i)] - 1) * (d1.rk[d1.get(i)] - 1);
	}
	cout << ans << "\n";
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/
