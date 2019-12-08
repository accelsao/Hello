struct KM{
	static const int N = 550;
	const int inf = 1e9+7;
	int n, match[N], vx[N], vy[N];
	int edge[N][N], lx[N], ly[N], slack[N];
	void init(int _n){
		n=_n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				edge[i][j]=0;
			}
	}
	void add_Edge(int u, int v, int w){
		edge[u][v]=w;
	}
	bool dfs(int x){
		vx[x]=1;
		for(int y=0;y<n;y++){
			if(vy[y])continue;
			if(lx[x]+ly[y]>edge[x][y]){
				slack[y]=min(slack[y], lx[x]+ly[y]-edge[x][y]);
			}
			else{
				vy[y]=1;
				if(match[y]==-1||dfs(match[y])){
					match[y]=x;
					return 1;
				}
			}
		}
		return 0;
	}
	int solve(){
		fill(match, match+n, -1);
		fill(lx, lx+n, -inf);
		fill(ly, ly+n, 0);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				lx[i]=max(lx[i], edge[i][j]);
			}
		for(int i=0;i<n;i++){
			fill(slack, slack+n, inf);
			while(1){
				fill(vx, vx+n, 0);
				fill(vy, vy+n, 0);
				if(dfs(i))break;
				int d=inf;
				for(int j=0;j<n;j++){
					if(!vy[j]){
						d=min(d, slack[j]);
					}
				}
				for(int j=0;j<n;j++){
					if(vx[j]){
						lx[j]-=d;
					}
					if(vy[j]){
						ly[j]+=d;
					}
					else{
						slack[j]-=d;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=edge[match[i]][i];
		}
		return ans;
	}
}km;
