REGEX -> NFA -> DFA -> MatrixPower 
Detail in editorial
```cpp
#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
vector<string> split_string(string);

vector<vector<pair<int, int>>> NFA_g;
int idx;
void buildNFA(const string &s, int u, int v) {
  if (s[idx] == 'a') {
    NFA_g[u].push_back({v, 1});
    idx++;
    return;
  }
  if (s[idx] == 'b') {
    NFA_g[u].push_back({v, 2});
    idx++;
    return;
  }
  int mid0 = NFA_g.size();
  NFA_g.push_back({});
  int mid1 = NFA_g.size();
  NFA_g.push_back({});
  idx++;
  buildNFA(s, mid0, mid1);

  if (s[idx] == '*') {
    NFA_g[mid1].push_back({mid0, 0});
    // 要有可以跳過 u-v 的情況 [0->u u->1] or [0->v v->1] or [0->v u->1 ]
    NFA_g[u].push_back({mid1, 0}); 
    NFA_g[mid1].push_back({v, 0});
    idx += 2;
    return;
  }
  if (s[idx] == '|') {
    NFA_g[u].push_back({mid0, 0});
    NFA_g[mid1].push_back({v, 0});
    idx++;
    buildNFA(s, mid0, mid1);
    idx++;
    return;
  }
  NFA_g[u].push_back({mid0, 0});
  buildNFA(s, mid1, v);
  idx++;
  return;
}
vector<pair<int, int>> DFA;
vector<int> vis;
vector<int> epsilon;

void dfs_eps(int x) {
  if (vis[x])
    return;
  vis[x] = 1;
  epsilon.push_back(x);
  for (const auto &e : NFA_g[x]) {
    if (e.second == 0)
      dfs_eps(e.first);
  }
}

void dfs(vector<int> state, int type) {
  vis = vector<int>(NFA_g.size(), 0);
  epsilon.clear();
  for (const int &u : state)
    for (const auto &e : NFA_g[u]) {
      if (e.second == type)
        dfs_eps(e.first);
    }
}
vector<vector<int>> Matrix;
vector<int> final_state;
void NFA2DFA() {
  map<vector<int>, int> E;
  vector<vector<int>> state;
  DFA.clear();
  DFA.push_back({-1, -1});
  epsilon.clear();
  vis = vector<int>(NFA_g.size(), 0);
  dfs_eps(0);
  sort(epsilon.begin(), epsilon.end());
  state.push_back(epsilon);
  int idx = 0;
  E[epsilon] = idx++;
  for (int i = 0; i < idx; i++) {
    // find a
    dfs(state[i], 1);
    sort(epsilon.begin(), epsilon.end());
    if (epsilon.size()) {
      if (E.find(epsilon) == E.end()) {
        E[epsilon] = idx++;
        state.push_back(epsilon);
        DFA.push_back({-1, -1});
      }
      DFA[i].first = E[epsilon];
    }
    // find b

    dfs(state[i], 2);
    sort(epsilon.begin(), epsilon.end());
    if (epsilon.size()) {
      if (E.find(epsilon) == E.end()) {
        E[epsilon] = idx++;
        state.push_back(epsilon);
        DFA.push_back({-1, -1});
      }
      DFA[i].second = E[epsilon];
    }
  }
  Matrix = vector<vector<int>>(idx, vector<int>(idx));
  for (int i = 0; i < idx; i++) {
    if (DFA[i].first != -1)
      Matrix[i][DFA[i].first]++;
    if (DFA[i].second != -1)
      Matrix[i][DFA[i].second]++;
  }
  final_state.clear();
  for (int i = 0; i < idx; i++) {
    // 1 is end of the NFA graph
    if (find(state[i].begin(), state[i].end(), 1) != state[i].end()) {
      final_state.push_back(i);
    }
  }
}
void mm(vector<vector<int>> &a, vector<vector<int>> b) {
  int n = a.size();
  vector<vector<int>> z(n, vector<int>(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      long s = 0;
      for (int k = 0; k < n; k++) {
        s += 1LL * a[i][k] * b[k][j] % M;
        s %= M;
      }
      z[i][j] = (int)s;
    }
  a = z;
}
void matrixpow(int pw) {
  int n = Matrix.size();
  vector<vector<int>> z(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    z[i][i] = 1;
  while (pw) {
    if (pw & 1) {
      mm(z, Matrix);
    }
    pw >>= 1;
    mm(Matrix, Matrix);
  }
  Matrix = z;
}

int countStrings(const string &s, int len) {
  NFA_g.clear();
  NFA_g.push_back({});
  NFA_g.push_back({});
  idx = 0;
  buildNFA(s, 0, 1);
  NFA2DFA();
  matrixpow(len);
  long sum = 0;
  for (const int &j : final_state) {
    sum += Matrix[0][j];
    sum %= M;
  }
  return (int)sum;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string rl_temp;
    getline(cin, rl_temp);

    vector<string> rl = split_string(rl_temp);

    string r = rl[0];

    int l = stoi(rl[1]);

    int result = countStrings(r, l);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}

```