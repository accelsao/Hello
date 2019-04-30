#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

const int M = 105;
int dfs_num, top, n, m;
vector<int>g[M];
int mat[M][M];//邊的數量 兩點間可能多邊 考慮奇偶
bool instk[M];//是否在棧中
bool mk[M];//把壓縮過的環中點標記,true 表示已壓縮
int sta[M];//tarjan 棧
int df[M], lw[M];//tarjan 參量
void init() {
	dfs_num = top = 0;
	for (int i = 0; i <= n; i++)
		g[i].clear();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			mat[i][j] = 0;
		instk[i] = mk[i] = sta[i] = df[i] = lw[i] = 0;
	}
}
/*
實施DFS
針對每一個點，計算自身與子孫所能觸及的最高祖先。
（觸及是指：不斷往下走tree edge、往上走back edge。）
每當發現某一點恰是最高祖先，即表示此點與子孫已經形成BCC。
從堆疊之中刪除BCC，避免再次處理
*/
void tarjan(int u, int p) {
	df[u] = ++dfs_num;
	lw[u] = dfs_num;
	instk[u] = 1;
	sta[top++] = u;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if(p==v&&mat[u][v]>1)
			if (mat[u][v] % 2 == 0) {//偶數邊 直接縮成點
				mk[u] = 1;
				continue;
			}
		if (!df[v]) {//first time
			tarjan(v, u);
			lw[u] = min(lw[u], lw[v]);
		}
		else if (v != p&&instk[v])//v is u's child && v is in stack
			lw[u] = min(lw[u], df[v]);	
	}
	if (df[u] == lw[u]) {//存在強連通分量
		//將這整個BCC退出棧
		int c = 1;
		top--;
		while (sta[top] != u) {//等於u時退出棧
			mk[sta[top--]] = 1;
			c++;
		}
		if (c && (c & 1))//如果節點奇數 保留一邊 包括u點最近的v點
			mk[sta[top + 1]] = 0;//u-v的邊 復原
	
	}
}
int sg(int u, int p) {
	int ans = 0;
	for (int i = 0; i < g[u].size(); i++)
		if (!mk[g[u][i]] && g[u][i] != p)
			ans ^= (sg(g[u][i], u) + 1);
	return ans;
}
int main() {
	int T;
	while (cin >> T) {
		int ans = 0;
		while (T--) {	
			cin >> n >> m;
			init();
			int u, v;
			for (int i = 0; i < m; i++) {
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
				mat[u][v]++, mat[v][u]++;
			}
			tarjan(1, -1);//Tarjan求連通分量
			ans ^= sg(1, -1);
		}
		puts(ans ? "Sally" : "Harry");
	}
}
