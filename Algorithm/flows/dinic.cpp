struct Dinic{
	static const int N = 2e5+10;
	static const int inf = 1e9+7;
	struct edge{
		int from, to, cap, flow;
	};
	int n, s, t, d[N], q[N], ptr[N];
	vector<edge> E;
	vector<int> g[N];
	void add_Edge(int u, int v, int cap){
		edge e1 = {u, v, cap, 0};
		edge e2 = {v, u, 0, 0};
		g[u].push_back((int)E.size());
		E.push_back(e1);
		g[v].push_back((int)E.size());
		E.push_back(e2);
	}
	bool bfs(){
		int qh=0, qt=0;
		q[qt++]=s;
		for(int i=0;i<=n;i++)d[i]=-1;
		d[s]=0;
		while(qh<qt&&d[t]==-1){
			int u=q[qh++];
			for(auto id:g[u]){
				int v=E[id].to;
				if(d[v]==-1 && E[id].flow < E[id].cap){
					q[qt++]=v;
					d[v]=d[u]+1;
				}
			}
		}
		return d[t]!=-1;
	}
	int dfs(int u, int flow){
		if(!flow)return 0;
		if(u==t)return flow;
		for(;ptr[u]<(int)g[u].size();ptr[u]++){
			int id=g[u][ptr[u]];
			int v=E[id].to;
			if(d[v]!=d[u]+1){
				continue;
			}
			int pushed=dfs(v, min(flow, E[id].cap-E[id].flow));
			if(pushed){
				E[id].flow+=pushed;
				E[id^1].flow-=pushed;
				return pushed;
			}
		}
		return 0;
	}
	int dinic(){
		int flow=0;
		while(bfs()){
			for(int i=0;i<=n;i++){
				ptr[i]=0;
			}
			while(int pushed=dfs(s, inf)){
				flow+=pushed;
			}
		}
		return flow;
	}
}D;

