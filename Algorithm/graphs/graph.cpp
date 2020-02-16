// include and define
#include <bits/stdc++.h>
using namespace std;

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

// Test
int main(){
  int n = 10;
  printf("=========  n=%d  ========\n", n);
  puts("===========undirectedgraph==========");
  {
    undirectedgraph<int> g(n);
    g.add(1, 2);
    g.add(2, 3);
    g.add(3, 4);
    g.add(4, 5);
    g.add(5, 6);
    g.add(6, 7);
    g.add(7, 8);
    g.add(7, 3);
    for(const auto &x: g.g) {
      debug(x);
    }
    for(const auto &x: g.edges) {
      debug(x.from, x.to, x.cost);
    }
  }
  puts("===========directedgraph==========");
  {
    directedgraph<int> g(n);
    g.add(1, 2);
    g.add(2, 3);
    g.add(3, 4);
    g.add(4, 5);
    g.add(5, 6);
    g.add(6, 7);
    g.add(7, 8);
    g.add(7, 3);
    for(const auto &x: g.g) {
      debug(x);
    }
    for(const auto &x: g.edges) {
      debug(x.from, x.to, x.cost);
    }
  }

}

