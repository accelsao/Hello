// ███▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓▓▓╬╬╬╬╬╬▓█
// ███▓███████▓▓╬╬╬╬╬╬╬╬╬╬╬╬▓███▓▓▓▓█▓╬╬╬▓█
// ███████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓█
// ████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬█
// ███▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ███▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓█
// ████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬█
// ███▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// ███▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// █████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█
// █████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
// █████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
// ████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██
// ████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓██
// █████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓██
// █████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬███
// ██████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓███
// ███████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬████
// ███████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓████
// ████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█████
// █████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓██████
// ██████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓███████
// ███████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓████████
// ██████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬██████████
// ███████████████▓▓▓██▓▓╬╬╬╬╬╬▓███████████
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T> using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll myRand(ll B) { return (ull)rng() % B; }

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A> string to_string(A v) {
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
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
//#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const ll INF = 2e18;
const int inf = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 1e9 + 7;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int dep[N];
int p[N];
int fa[N][20];
int fb[N][20];
vector<vector<pii>> con;

void dfs(int u) {
  for (int j = 1; j < 20; j++) {
    fa[u][j] = fa[fa[u][j - 1]][j - 1];
  }
  for (int j = 1; j < 20; j++) {
    fb[u][j] = max(fb[u][j - 1], fb[fa[u][j - 1]][j - 1]);
  }
  for (auto e : con[u]) {
    int v = e.first;
    if (v != fa[u][0]) {
      fb[v][0] = e.second;
      fa[v][0] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
  }
}

int getlca(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  for (int j = 0; j < 20; j++) {
    if (((dep[x] - dep[y]) >> j) & 1) {
      x = fa[x][j];
    }
  }
  if (x == y) {
    return x;
  }
  for (int j = 19; j >= 0; j--) {
    if (fa[x][j] != fa[y][j]) {
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  return fa[x][0];
}

int getmax(int u, int p) {
  int ans = 0;
  for (int j = 19; j >= 0; j--) {
    if ((dep[u] - dep[p]) >= (1 << j)) {
      ans = max(ans, fb[u][j]);
      u = fa[u][j];
    }
  }
  return ans;
}

void minpth(int u, int p, int v) {
  for (int j = 19; j >= 0; j--) {
    if ((dep[u] - dep[p]) >= (1 << j)) {
      fb[u][j] = min(fb[u][j], v);
      u = fa[u][j];
    }
  }
}

inline int find(int x) { return (x == p[x]) ? x : p[x] = find(p[x]); }

struct edges {
  int u, v, w, idx;
  edges(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx) {}
  bool operator<(const edges &a) const { return w < a.w; }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  vector<edges> g;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.push_back(edges(u, v, w, i));
  }
  sort(all(g));

  vector<bool> mst(m, false);
  con.resize(n + 1);
  for (const auto &e : g) {
    int x = find(e.u);
    int y = find(e.v);
    if (x != y) {
      p[x] = y;
      mst[e.idx] = true;
      con[e.u].emplace_back(e.v, e.w);
      con[e.v].emplace_back(e.u, e.w);
    }
  }

  dep[1] = 1;
  dfs(1);
  vector<int> ans(m);
  for (const auto &e : g) {
    if (!mst[e.idx]) {
      int lca = getlca(e.u, e.v);
      ans[e.idx] = max(getmax(e.u, lca), getmax(e.v, lca));
    }
  }

  for (int j = 0; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      fb[i][j] = (int)1e9;
    }
  }

  for (const auto &e : g) {
    if (!mst[e.idx]) {
      int lca = getlca(e.u, e.v);
      minpth(e.u, lca, e.w);
      minpth(e.v, lca, e.w);
    }
  }

  for (int j = 19; j > 0; j--) {
    for (int i = 1; i <= n; i++) {
      fb[i][j - 1] = min(fb[i][j - 1], fb[i][j]);
      fb[fa[i][j - 1]][j - 1] = min(fb[fa[i][j - 1]][j - 1], fb[i][j]);
    }
  }

  for (auto e : g) {
    if (mst[e.idx]) {
      int u = e.u;
      int v = e.v;
      if (fa[u][0] == v) {
        ans[e.idx] = fb[u][0];
      } else {
        ans[e.idx] = fb[v][0];
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }
}
