/*
binary trie
code from http://blog.csdn.net/SolarDomo/article/details/52167799
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 100000 + 500;
#define LL long long
int ch[32 * maxn][2];
LL value[32 * maxn];
int node_cnt;

inline void init() {
	node_cnt = 1;
	memset(ch[0], 0, sizeof(ch));
}

inline void Insert(LL x) {
	int cur = 0;
	for (int i = 32; i >= 0; --i) {
		int idx = (x >> i) & 1;
		if (!ch[cur][idx]) {
			memset(ch[node_cnt], 0, sizeof(ch[node_cnt]));
			ch[cur][idx] = node_cnt;
			value[node_cnt++] = 0;
		}
		cur = ch[cur][idx];
	}
	value[cur] = x;
}

inline LL Query(LL x) {
	int cur = 0;
	for (int i = 32; i >= 0; --i) {
		int idx = (x >> i) & 1;
		if (ch[cur][idx ^ 1]) cur = ch[cur][idx ^ 1];
		else cur = ch[cur][idx];
	}
	return value[cur];	
}

struct Edge {
	int v, next, c;
}edge[maxn * 2];
int head[maxn];
int tot;
void Add_Edge(int u, int v, int w) {
	edge[tot].v = v;
	edge[tot].c = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void init_Adj() {
	tot = 0;
	memset(head, -1, sizeof(head));
}
LL ans;
void DFS(int cur, int cur_xor, int _fa) {
	LL d = Query(cur_xor);
	ans = max(ans, cur_xor ^d);
	Insert(cur_xor);
	for (int i = head[cur]; ~i; i = edge[i].next) {
		if (edge[i].v != _fa) {
			DFS(edge[i].v, cur_xor ^ edge[i].c, cur);
		}
	}
}
int main() {
	int n, u, v, w;
	while (cin>>n) {
		init_Adj();
		for (int i = 0; i < n - 1; ++i) {
			cin >> u >> v >> w;
			Add_Edge(u, v, w);
			Add_Edge(v, u, w);
		}
		init();
		ans = 0;
		DFS(0, 0, -1);
		printf("%d\n", ans);
	}
}
