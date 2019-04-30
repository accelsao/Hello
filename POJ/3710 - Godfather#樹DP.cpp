#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e6 + 5;
struct edge{
	int to, nxt;
}e[N];
int head[N], n, x, y, t, sz[N], ms[N],k;
vector<int>v;
void add(int x, int y){
	e[t].to = y;
	e[t].nxt = head[x];
	head[x] = t++;
}
void dfs(int u, int p){
	sz[u] = 1, ms[u] = 0;
	for (int i = head[u]; ~i; i = e[i].nxt){
		if (e[i].to == p)continue;
		dfs(e[i].to, u);
		sz[u] += sz[e[i].to];
		ms[u] = max(ms[u], sz[e[i].to]);
	}
	ms[u] = max(ms[u], n - sz[u]);
	return;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)head[i] = -1;
	for (int i = 1; i < n; i++)
		scanf("%d%d", &x, &y), add(x, y), add(y, x);
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		if (ms[i] <= n / 2){
			if (k)putchar(' ');
			printf("%d", i);
			k = 1;
		}
	puts("");
}
