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
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
//#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// graph
template<typename T>
class graph {
public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector<edge> edges;
  vector< vector<int> > g;
  int n;
  graph(int _n) : n(_n) {
    g.resize(n);
  }
  virtual int add(int from, int to, T cost) = 0;
};

// undirectedgraph
template <typename T>
class undirectedgraph : public graph<T> {
public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undirectedgraph(int _n) : graph<T>(_n) {
  }
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

// directedgraph
template <typename T>
class directedgraph : public graph<T> {
public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  directedgraph(int _n) : graph<T>(_n) {
  }
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

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
	int n,m,k;
	cin>>n>>m>>k;
    undirectedgraph<int> g(n);
    int u, v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        u--, v--;
        g.add(u, v, 1);
    }
    for(int i=0;i<k;i++){
        cin>>u>>v;
        u--, v--;
        g.add(u, v, -1);
    }

    dsu d(n);

    for(auto e : g.edges) {
        if(e.cost==1){
            d.unite(e.from, e.to);
        }

    }
    for(int i=0;i<n;i++){
        d.get(i);
    }
    debug(d.p);
    debug(d.rk);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        debug(d.rk[i]);
        ans[i] = d.rk[d.p[i]] - 1;
    }
    debug(ans);
    for(auto e : g.edges) {
        int u=e.from;
        int v=e.to;
        if(d.p[u] == d.p[v]) {
            ans[u]--;
            ans[v]--;
        }

    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }


}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/
