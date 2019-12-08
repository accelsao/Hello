struct TarjanSCC{
	static const int N=1e6+10;
	int n, vis[N], low[N], belong[N], df, scc;
	vector<int> g[N];
	stack<int> stk;
	void tarjan(int u){
		vis[u]=low[u]=++df;
		stk.push(u);
		for(auto v:g[u]){
			if(!vis[v]){
				tarjan(v);
				low[u]=min(low[u], low[v]);
			}
			else if(!belong[v]){
				low[u]=min(low[u], vis[v]);
			}
		}
		if(vis[u]==low[u]){
			belong[u]=++scc;
			while(stk.size()&&stk.top()!=u){
				belong[stk.top()]=scc;
				stk.pop();
			}
			stk.pop();
		}
	}
	void init(int _n){
		n=_n;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		memset(low, 0, sizeof(low));
		memset(belong, 0, sizeof(belong));
		memset(vis, 0, sizeof(vis));
		df=scc=0;
		
	}
	void add_Edge(int u,int v){
		g[u].push_back(v);
	}
	void solve(){
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				tarjan(i);
			}
		}
	}
}tarjanscc;
