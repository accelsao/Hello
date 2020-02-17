#include <bits/stdc++.h>
using namespace std;

// manacher.
template<typename T>
vector<int> manacher(int n, const T& s) {
  if(n == 0) {
    return vector<int>();
  }
  assert(n > 0);
  vector<int> z(n + n - 1);
  // z[i] := (s[i - k + 1] == s[i + k - 1]) for k = 1 to z[i]
  int l = -1, r = -1;
  for(int k = 0; k < n + n - 1; k++) {
    int i = (k + 1) >> 1;
    int j = k >> 1;
    int p = (i >= r ? 0 : min(r - i, z[2 * (l + r) - k]));
    while(j + p + 1 < n && i - p - 1 >= 0 && s[j + p + 1] == s[i - p - 1]) {
      p++;
    }
    if(j + p > r) {
      l = i - p;
      r = j + p;
    }
    z[k] = p;
  }
  return z;
  // res[2 * i] = odd radius in position i
  // res[2 * i + 1] = even radius between positions i and i + 1
  // s = "abaa" -> res = {0, 0, 1, 0, 0, 1, 0}
  // in other words, for every z from 0 to 2 * n - 2:
  // calculate i = (z + 1) >> 1 and j = z >> 1
  // now there is a palindrome from i - res[z] to j + res[z]
  // (watch out for i > j and res[z] = 0)
  // from @the-tourist
}

template <typename T>
vector<int> manacher(const T& s) {
  return manacher((int)s.size(), s);
}


// debug
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

// Test
int main(){
  string s = "abaabaab";
  int n = s.size();
  auto vec = manacher(s);
  debug(vec);
}

  // [vec]: {0, 0, 1, 0, 0, 3, 0, 0, 3, 0, 0, 2, 0, 0, 0}
