//以下code 全不能求出真正的次小 只能判斷最小唯一  怒!!!
// 0ms版 別人的
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

#define scanf scanf_s
const int INF = 0x3f3f3f3f;

struct edge
{
	int u, v, w, last;
}ed[10010], ad[10010];

int n, m, T, ans = 0, bns = INF, tot = 0, num = 0;
int head[1010], dep[1010], st[1010][20], anc[1010][20];
int fa[1010], used[10010];

void add(int u, int v, int w)
{
	num++;
	ed[num].u = u;
	ed[num].v = v;
	ed[num].w = w;
	ed[num].last = head[u];
	head[u] = num;
}

int getfather(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = getfather(fa[x]);
}

bool cmp(const edge &a, const edge &b)
{
	return a.w<b.w;
}

void Kruscal()
{
	sort(ad + 1, ad + m + 1, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x = getfather(ad[i].u), y = getfather(ad[i].v);
		if (x != y)
		{
			tot++, fa[x] = y, ans += ad[i].w, used[i] = 1;
			add(ad[i].u, ad[i].v, ad[i].w), add(ad[i].v, ad[i].u, ad[i].w);
		}
		if (tot == n - 1) break;
	}
}

void dfs(int u, int f)
{
	anc[u][0] = f;
	for (int i = 1; i <= 18; i++)
		anc[u][i] = anc[anc[u][i - 1]][i - 1],
		st[u][i] = max(st[u][i - 1], st[anc[u][i - 1]][i - 1]);
	for (int i = head[u]; i; i = ed[i].last)
	{
		int v = ed[i].v;
		if (v == f) continue;
		dep[v] = dep[u] + 1, st[v][0] = ed[i].w;
		dfs(v, u);
	}
}

int lca(int u, int v)
{
	int rt = 0;
	if (dep[u]<dep[v]) swap(u, v);
	for (int i = 18; i >= 0; i--)
		if (dep[anc[u][i]] >= dep[v])
			rt = max(rt, st[u][i]), u = anc[u][i];
	if (u == v) return rt;
	for (int i = 18; i >= 0; i--)
		if (anc[u][i] != anc[v][i])
			rt = max(rt, max(st[u][i], st[v][i])), u = anc[u][i], v = anc[v][i];
	return max(rt, max(anc[u][0], anc[v][0]));
}

void init()
{
	memset(head, 0, sizeof(head));
	memset(fa, 0, sizeof(fa));
	memset(dep, 0, sizeof(dep));
	memset(st, 0, sizeof(st));
	memset(anc, 0, sizeof(anc));
	memset(used, 0, sizeof(used));
	num = ans = tot = 0;
	bns = INF;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
			scanf("%d%d%d", &ad[i].u, &ad[i].v, &ad[i].w);
		Kruscal();
		dfs(1, 1);
		for (int i = 1; i <= m; i++)
		{
			if (used[i]) continue;
			int u = ad[i].u, v = ad[i].v;
			bns = min(bns, ad[i].w - lca(u, v));
		}
		if (bns) printf("%d\n", ans);
		else printf("Not Unique!\n");
		//dep[1]; cout << dep[2];
	}
	return 0;
}
//改一改又變32MS 原因不管了
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;


struct edge{
	int u, v, w, last;
}ed[10010], ad[10010];

int n, m, T, ans = 0, bns = 1e9, tot = 0, num = 0;
int head[1010], dep[1010], st[1010][20], anc[1010][20];
int fa[1010], used[10010];

void add(int u, int v, int w){
	num++;
	ed[num].u = u;
	ed[num].v = v;
	ed[num].w = w;
	ed[num].last = head[u];
	head[u] = num;
}

int getfather(int x){
	return x == fa[x] ? x : fa[x] = getfather(fa[x]);
}

bool cmp(const edge &a, const edge &b){
	return a.w<b.w;
}

void Kruscal(){
	sort(ad + 1, ad + m + 1, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++){
		int x = getfather(ad[i].u), y = getfather(ad[i].v);
		if (x == y)continue;
		tot++, fa[x] = y, ans += ad[i].w, used[i] = 1;
		add(ad[i].u, ad[i].v, ad[i].w), add(ad[i].v, ad[i].u, ad[i].w);	
		if (tot == n - 1) break;
	}
}

void dfs(int u, int f){
	//st
	anc[u][0] = f;
	for (int i = 1; (1<<i)<=n; i++)
		anc[u][i] = anc[anc[u][i - 1]][i - 1],
		st[u][i] = max(st[u][i - 1], st[anc[u][i - 1]][i - 1]);
	//dfs
	for (int i = head[u]; i; i = ed[i].last){
		int v = ed[i].v;
		if (v == f) continue;
		dep[v] = dep[u] + 1, st[v][0] = ed[i].w;
		dfs(v, u);
	}
}

int lca(int u, int v){
	int rt = 0;
	if (dep[u]<dep[v]) swap(u, v);
	int x = dep[u] - dep[v], y = 0;
	while (x) {
		if (x & 1) {
			rt = max(rt, st[u][y]);
			u = anc[u][y];
		}
		x >>= 1;
		y++;
	}
	if (u == v) return rt;
	for (x = 1; (1 << x) <= dep[u]; x++);
	while (--x >= 0) {
		if (anc[u][x] != anc[v][x]) {
			rt = max(rt, max(st[u][x], st[v][x])), u = anc[u][x], v = anc[v][x];
		}
	}
	return max(rt, max(anc[u][0], anc[v][0]));
}

void init()
{
	memset(head, 0, sizeof(head));
	memset(fa, 0, sizeof(fa));
	memset(dep, 0, sizeof(dep));
	memset(st, 0, sizeof(st));
	memset(anc, 0, sizeof(anc));
	memset(used, 0, sizeof(used));
	num = ans = tot = 0;
	bns = 1e9;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--){
		init();
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
			cin >> ad[i].u >> ad[i].v >> ad[i].w;
		Kruscal();
		dfs(1, 1);
		for (int i = 1; i <= m; i++){
			if (used[i]) continue;
			int u = ad[i].u, v = ad[i].v;
			bns = min(bns, ad[i].w - lca(u, v));
		}
		if (bns) printf("%d\n", ans);
		else printf("Not Unique!\n");
	}
}


//32MS  它add完邊才sort 在DFS  我覺得可能是錯的 待測試zj c370
// kruskal lca
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;


int n, m;
#define N 10005
#define M 100005
int p[N][15], mm[N][15], deep[N], head[N],f[N], tot = 0;
struct Edge {
	int to, next, w;
	int select;
	Edge() {}
	Edge(int _to, int _next, int _w) :to(_to), next(_next), w(_w){ select = 0; }
}e[M];
bool cmp(const Edge &x, const Edge &y) {
	return x.w<y.w;
}
void init() {
	memset(head, -1, sizeof(head));
	memset(deep, 0, sizeof(deep));
	memset(mm, 0, sizeof(mm));
	tot = 0;
}
void add(int u,int v,int w) {
	e[tot] = Edge(v, head[u], w);
	head[u] = tot++;
	e[tot] = Edge(u, head[v], w);
	head[v] = tot++;
}
int find(int x){
	return f[x] == x ? x :f[x] = find(f[x]);
}
void dfs(int u) {
	for (int i = head[u]; ~i; i = e[i].next) {
		int v = e[i].to;
		if (!deep[v] && e[i].select) {
			p[v][0] = u;
			deep[v] = deep[u] + 1;
			mm[v][0] = e[i].w;
			dfs(v);
		}
	
	}
}
/*
定义一个数组p[i][j]代表的是从i节点往上的第2^j个节点是多少
这样可以得到一个递推方程式
i往上走2^(j-1)再走2^(j-1)刚好是往上走的第2^j个节点
p[i][j]=p[p[i][j-1]][j-1]
*/
void st() {
for(int j=1;(1<<j)<=n;j++)
	for(int i=1;i<=n;i++)
		if (p[i][j - 1] != -1) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			mm[i][j] = max(mm[i][j - 1], mm[p[i][j - 1]][j - 1]);
		}
}
int del(int a, int b) {//mst_lca 要刪除的邊  刪完後 在加上邊i 找次小
	if (deep[a] < deep[b])swap(a, b);
	int x = deep[a] - deep[b], y = 0, m = 0;
	while (x) {
		if (x & 1) {
			m = max(m, mm[a][y]);
			a = p[a][y];
		}
		x >>= 1;
		y++;
	}
	if (a == b)return m;
	//這題用不到  測資太弱  邊權重很多相等時會發生a!=b  
	/*for (x = 1; (1 << x) <= deep[a]; x++);
	while (--x >= 0) {
		if (p[a][x] != -1 && p[a][x] != p[b][x]) {
			m = max(mm[a][x], m);
			a = p[a][x];
			m = max(mm[b][x], m);
			b = p[b][x];
		}
	}
	return m = (max(mm[a][0], max(mm[b][0], m)));*/
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		init();
		for (int i = 0; i <= n; i++)
			f[i] = i;
		int x, y, d;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> d;
			add(x, y, d);
		}
		int ans = 0;
		sort(e, e + tot,cmp);
		for (int i = 0; i < tot; i += 2) {
			int x = find(e[i].to), y = find(e[i ^ 1].to);
			if (x == y)continue;
			ans += e[i].w;
			e[i].select = e[i ^ 1].select = 1;
			f[x] = y;
		}
		p[1][0] = -1;
		deep[1] = 1;
		dfs(1);
		st();
		int sec = 1 << 30;
		for (int i = 0; i < tot; i += 2) 
			if (!e[i].select) 
				sec = min(sec, ans - del(e[i].to, e[i ^ 1].to) + e[i].w);
		1;
		if (sec == ans)puts("Not Unique!");
		else printf("%d\n", ans);
	}
}
// 16ms  假解 應該是測資太弱 所以以下方法快2倍 有些測資會WA
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;


#define INF 99999999  
#define N 110  
#define MAX(a,b) (a)>(b)?(a):(b)  

#define scanf scanf_s

int n, G[N][N], f[N][N];

void prim()
{
	int p[N], vis[N], i, j, v, sum, k;

	memset(vis, 0, sizeof(vis));
	memset(f, 0, sizeof(f));

	k = 0;
	p[k++] = 1;//存放最小生成树点集合   
	vis[1] = 1;

	sum = 0;

	for (int t = 1; t<n; t++) { // n个顶点，n-1条边，循环n-1次，每次加入一条新的边   

		int min = INF;
		int s, e;

		for (j = 0; j<k; j++) {//枚举书中已有的每个点   
			v = p[j];
			for (i = 1; i <= n; i++) { //寻找点v相连的最小边；   
				if (!vis[i] && G[v][i]<min) {
					min = G[v][i];
					s = v; e = i;//记录新加入边的两端点   
				}
			}
		}
		for (j = 0; j<k; j++) { //找到要新加入的边，  
			v = p[j];
			f[e][v] = f[v][e] = max(f[v][s], G[s][e]);
		}

		G[s][e] = G[e][s] = INF; //INF 代表该边已被删除   

		p[k++] = e;//加入新结点   
		vis[e] = 1; //标记   

		sum += min; //求最小生成树的权值   
	}


	/********判断是否存在次小生成树，或者最小生成树是否唯一 ********/

	int flag = 1; //标记是否有次小生成树   
	int sign = 0; //标记是否所有的边都在最小生成树中 0代表是， 1代表不是   

	for (i = 1; i <= n; i++) { //枚举图中剩余的不在最小生成树的边   
		for (j = 1; j <= n; j++) {
			if (G[i][j] != INF) {  //存在图中不在最小生成树的边  
				sign = 1;  //标记还存在其他边   
				if (i != j && G[i][j] != f[i][j]) {
					flag = 0;
				}
			}
		}
	}
	if (flag && sign) printf("Not Unique!\n"); //   
	else printf("%d\n", sum);
}

int main()
{
	int t, m, i, j, a, b, c;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)
				G[i][j] = INF;
		}
		while (m--) {
			scanf("%d%d%d", &a, &b, &c);
			G[a][b] = G[b][a] = c;
		}
		prim();

	}
}
