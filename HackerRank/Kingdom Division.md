# Problem
給你tree n個點 n-1條邊
每個點有兩種顏色, 任一點必定要有至少一個相鄰同色點, 符合條件的組合數有多少個?

# Solution
把1當成root, 轉成有根樹, 對於每個node考慮兩種情況
1. cur和parent同色
代表他的children可以為任意顏色
2. cur和parent異色
代表他的children至少1個同色 (可以轉換成任意顏色扣掉全部都是異色)

定義dp[node][0] 是cur和parent同色, dp[node][1] 是cur和parent異色
答案為dp[root][1] * 2 因為可以填入兩種顏色

dp[cur][0] = ALL(dp[children][0] + dp[children][1])
dp[cur][1] = ALL(dp[children][0] + dp[children][1]) - ALL(dp[children][1])
// ALL要把組合相乘

```cpp
#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7;
const int N = 1e5+10;

vector<int> g[N];
vector<long>f_same;// cur and parent are same color
vector<long>f_dif;// different

void dfs(int u, int p){
    f_same[u]=1;
    f_dif[u]=1;
    // printf("u:%d p:%d\n", u, p);
    for(const auto &v:g[u]){
        if(v == p)continue;
        dfs(v, u);
        f_same[u] *= (f_same[v] + f_dif[v]) % M; // because u == p , so v dont care
        f_dif[u] *= f_dif[v]; // u!=p so at least one u == v
        f_same[u] %= M;
        f_dif[u] %= M;
    }
    f_dif[u] = (f_same[u] - f_dif[u] + M) % M;
}
// Complete the kingdomDivision function below.
long kingdomDivision(int n, vector<vector<int>> roads) {
    for(int i=0; i<n-1; i++){
        int u=roads[i][0], v=roads[i][1];
        // printf("%d %d\n", u, v);
        g[u].push_back(v);
        // printf("%d %d\n", u, v);
        g[v].push_back(u);
    }
    // cout <<" 222\n";
    f_same.resize(n);
    f_dif.resize(n);
    dfs(0, -1);
    // printf("??\n");
    return 2 * f_dif[0] % M;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> roads(n-1);
    for (int i = 0; i < n-1; i++) {
        roads[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> roads[i][j];
            roads[i][j]--;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = kingdomDivision(n, roads);

    fout << result << "\n";

    fout.close();

    return 0;
}

```


