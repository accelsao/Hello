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

template <class T> bool set_max(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool set_min(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

std::mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const ll INF = 2e18;
const int inf = 1e9 + 7;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

std::vector<int> primes;
std::vector<int> inv; // (1 - 1/p)

ll getMask(int v) {
  ll mask = 0;
  for (int j = 0; j < (int)primes.size(); j++) {
    if (v % primes[j] == 0) {
      mask |= 1LL << j;
    }
  }
  return mask;
}

ll pw(ll a, int b = MOD - 2) {
  ll t = 1;
  while (b > 0) {
    if (b & 1) {
      t = t * a % MOD;
    }
    a = a * a % MOD;
    b /= 2;
  }
  return t;
}

struct LazyContext {

  LazyContext() { init(); }

  LazyContext(ll _x, ll _mask) {
    x = _x;
    mask = _mask;
  }

  void init() {
    x = 1;
    mask = 0;
  }

  void operator+=(LazyContext a) {
    x = x * a.x % MOD;
    mask |= a.mask;
  }

  ll x;
  ll mask;
};

struct Node {
  Node() {
    x = 1;
    mask = 0;
    size = 0;
  }
  Node(int v) {
    x = v;
    mask = getMask(v);
    size = 1;
  }
  Node(Node &l, Node &r) {
    x = (ll)l.x * r.x % MOD;
    mask = l.mask | r.mask;
    size = l.size + r.size;
  }
  void apply(LazyContext lazy) {
    x = (ll)x * pw(lazy.x, size) % MOD;
    mask |= lazy.mask;
  }

  ll get() {
    ll t = x;
    for (int j = 0; j < (int)primes.size(); j++) {
      if ((mask >> j) & 1) {
        t = t * inv[j] % MOD;
      }
    }
    return t;
  }

  ll x;
  ll mask;
  int size;
};

template <class i_t, class e_t, class lazy_count = int> class SegmentTree {
public:
  void init(vector<e_t> &base) {
    n = base.size();
    h = 0;
    while ((1 << h) < n) {
      h++;
    }
    tree.resize(n * 2);
    dirty.assign(n, false);
    lazy.resize(n);
    for (int i = 0; i < n; i++) {
      tree[i + n] = i_t(base[i]);
    }
    for (int i = n - 1; i > 0; i--) {
      tree[i] = i_t(tree[i * 2], tree[i * 2 + 1]);
      lazy[i].init();
    }
  }

  i_t query(int l, int r) {
    if (l >= r) {
      return i_t();
    }
    l += n;
    r += n;
    push(l);
    push(r - 1);
    i_t lp, rp;

    for (; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        lp = i_t(lp, tree[l++]);
      }
      if (r & 1) {
        // printf("tree[r-1]: %lld, %lld\n", tree[r - 1].x, tree[r - 1].mask);
        rp = i_t(tree[--r], rp);
      }
    }

    // printf("lp = %d, rp = %d\n", lp.get(), rp.get());
    // cout << lp.get() << endl;
    // cout << rp.get() << endl;

    return i_t(lp, rp);
  }

  void upd(int l, int r, lazy_count lc) {
    if (l >= r) {
      return;
    }
    l += n;
    r += n;
    // debug(l, r);
    push(l);
    push(r - 1);
    int l0 = l, r0 = r;
    for (; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        apply(l++, lc);
      }
      if (r & 1) {
        apply(--r, lc);
      }
    }
    build(l0);
    build(r0 - 1);
  }

private:
  int n, h;
  std::vector<bool> dirty;
  std::vector<i_t> tree;
  std::vector<lazy_count> lazy;

  void apply(int x, lazy_count &lc) {
    tree[x].apply(lc);
    if (x < n) {
      dirty[x] = true;
      lazy[x] += lc;
    }
  }

  void push(int x) {
    for (int s = h; s > 0; s--) {
      int i = x >> s;
      if (dirty[i]) {
        apply(i * 2, lazy[i]);
        apply(i * 2 + 1, lazy[i]);
        lazy[i].init();
        dirty[i] = false;
      }
    }
  }

  void build(int x) {
    for (x /= 2; x > 0; x /= 2) {
      tree[x] = i_t(tree[x * 2], tree[x * 2 + 1]);
      if (dirty[x]) {
        tree[x].apply(lazy[x]);
      }
    }
  }
};

int main() {
  // 1114F
  ios::sync_with_stdio(0), cin.tie(0);

  std::vector<bool> isPrime(350, true);
  for (int i = 2; i <= 300; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
    for (int j : primes) {
      int k = j * i;
      if (k < 350) {
        isPrime[k] = false;
      }
    }
  }

  for (int j : primes) {
    inv.push_back((j - 1) * pw(j, MOD - 2) % MOD);
  }

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SegmentTree<Node, int, LazyContext> tree;
  tree.init(a);

  while (q--) {
    std::string str;
    cin >> str;
    if (str[0] == 'T') {
      int l, r;
      cin >> l >> r;
      std::cout << tree.query(l - 1, r).get() << '\n';
    } else {
      int l, r, v;
      cin >> l >> r >> v;
      tree.upd(l - 1, r, LazyContext(v, getMask(v)));
    }
  }
}
