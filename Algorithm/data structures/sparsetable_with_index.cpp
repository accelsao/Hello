#include<bits/stdc++.h>
using namespace std;

// SparseTable
template <typename T, class F = function<pair<T, int>(const T&, const T&)>>
class SparseTable {
public:
    int n;
    vector<vector<pair<T, int>>> st;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        st.resize(max_log);
        st[0].resize(n);

        for(int i = 0; i < n; i++) {
          st[0][i].first = a[i];
          st[0][i].second = i;
        }
        for (int j = 1; j < max_log; j++) {
            st[j].resize(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[j][i] = func(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pair<T, int> get(int l, int r) const {
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 31 - __builtin_clz(r - l + 1);
        return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
    }
};

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
#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
    // INIT
    vector<int> a;
    a.resize(6);
    for(int i=0;i<6;i++){
      a[i] = rand() % 100;
    }
    // INIT

    // USAGE
    auto fun = [&](pair<int, int> i, pair<int, int> j) { return max(i, j); };
    SparseTable<int, decltype(fun)> st(a, fun);
    // USAGE

    // TEST
    for(int i = 0; i < a.size(); i++)
    for(int j = i; j < a.size(); j++){
        pair<int, int> res = {-1, -1};
        for(int k = i; k <= j; k++){

            res = max(res, {a[k], k});
        }
        assert(res == st.get(i, j));
    }
    puts("PASS");
    // TEST
}
