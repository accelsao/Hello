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

// blossom / find_max_unweighted_matching
template <typename T>
vector<int> find_max_unweighted_matching(const undirectedgraph<T>& g) {
  std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  vector<int> match(g.n, -1); // �ǰt
  vector<int> aux(g.n, -1);   // �ɶ��W�O
  vector<int> label(g.n);     // "o" or "i"
  vector<int> orig(g.n);      // ���
  vector<int> parent(g.n, -1);// ���`�I
  queue<int> q;
  int aux_time = -1;

  auto lca = [&](int v, int u) {
    aux_time++;
    while(true) {
      if(v != -1) {
        if (aux[v] == aux_time) { //�����X�L���I �]�N�OLCA
          return v;
        }
        aux[v] = aux_time;
        if(match[v] == -1) {
          v = -1;
        } else {
          v = orig[parent[match[v]]]; //�H�ǰt�I�����`�I�~��M��
        }
      }
      swap(v, u);
    }
  }; // lca

  auto blossom = [&](int v, int u, int a) {
    while(orig[v] != a) {
      parent[v] = u;
      u = match[v];
      if(label[u] == 1) {     // ��l�I�]��"o" ��W�s��
        label[u] = 0;
        q.push(u);
      }
      orig[v] = orig[u] = a;  // �Y��
      v = parent[u];
    }
  }; //blossom

  auto augment = [&](int v) {
    while(v != -1) {
      int pv = parent[v];
      int next_v = match[pv];
      match[v] = pv;
      match[pv] = v;
      v = next_v;
    }
  }; //augment

  auto bfs = [&](int root) {
    fill(label.begin(), label.end(), -1);
    iota(orig.begin(), orig.end(), 0);
    while(!q.empty()) {
      q.pop();
    }
    q.push(root);
    // ��l�I�]�� "o", �o�̥H"0"�N��"o", "1"�N��"i"
    label[root] = 0;
    while(!q.empty()) {
      int v = q.front();
      q.pop();
      for(int id : g.g[v]) {
        auto &e = g.edges[id];
        int u = e.from ^ e.to ^ v;
        if(label[u] == -1) { //��쥼���X�I
          label[u] = 1; // �аO "i"
          parent[u] = v;
          if(match[u] == -1) { //��쥼�ǰt�I
            augment(u); // �M��W�s���|
            return true;
          }
          // ���w�ǰt�I �N�P�o�ǰt���I��Jqueue ���������
          label[match[u]] = 0;
          q.push(match[u]);
          continue;
        } else if(label[u] == 0 && orig[v] != orig[u]){ //���w���X�I �B�аO�P��"o" �N����"��"
            int a = lca(orig[v], orig[u]);
            // ��LCA �M���Y��
            blossom(u, v, a);
            blossom(v, u, a);
        }
      }
    }
    return false;
  }; //bfs

  auto greedy = [&]() {
    vector<int> order(g.n);
    // �H������ order
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);

    // �N�i�H�ǰt���I�ǰt
    for(int i : order) {
      if(match[i] == -1) {
        for(auto id : g.g[i]) {
          auto &e = g.edges[id];
          int to = e.from ^ e.to ^ i;
          if(match[to] == -1) {
            match[i] = to;
            match[to] = i;
            break;
          }
        }
      }
    }
  }; // greedy

  // �@�}�l���H���ǰt
  greedy();
  // �良�ǰt�I��W�s��
  for (int i = 0; i < g.n; i++) {
    if (match[i] == -1) {
      bfs(i);
    }
  }
  return match;
}

int main(){
  int n = 10;
  undirectedgraph<int> g(n);
  g.add(1, 2);
  g.add(2, 3);
  g.add(3, 4);
  g.add(4, 5);
  g.add(5, 6);
  g.add(6, 7);
  g.add(7, 8);
  g.add(7, 3);
  auto vec = find_max_unweighted_matching(g);
  debug(vec);
  // [vec]: {-1, 2, 1, 4, 3, 6, 5, 8, 7, -1}
}

