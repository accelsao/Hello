#include <bits/stdc++.h>
#define Re(a,b) memset(a,b,sizeof a)
#define inf 1e9
#define N 105
using namespace std;
int n,k,S,T,tot,flow;
int head[N],dis[N],q[N];
struct edge{int to,next,f;}e[20005];
int a[N],b[N],c[N],fl[200005];
void add(int x,int y,int z){
	e[tot]=edge{y,head[x],z};
	head[x]=tot++;
	e[tot]=edge{x,head[y],0};
	head[y]=tot++;
}
bool bfs(){
	Re(dis,-1);
	queue<int>q;
	q.push(S);
	dis[S]=0;
	while(q.size()){
		int u=q.front();q.pop();
		if(u==T)return 1;
		for (int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if (dis[v]==-1&&e[i].f)
				dis[v]=dis[u]+1,q.push(v);
		}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int rest=flow,k;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	return flow-rest;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for (int i=2;i<=100000;i++)
		for (int j=i*2;j<=200000;j+=i)
			fl[j]=1;
	int l=1,r=n,mid,ans=-1;
	S=0,T=n+1;
	while (l<=r){
		mid=l+r>>1;
		Re(head,0);
		tot=2,flow=0;
		int mx=-1,pos=-1;
		for (int i=1;i<=n;i++)
			if (c[i]<=mid&&b[i]==1&&a[i]>mx)
				mx=a[i],pos=i;
		for (int i=1;i<=n;i++)
			if (c[i]<=mid){
				if (b[i]==1&&pos!=i) continue;
				flow+=a[i];
				if (b[i]&1){
					add(S,i,a[i]);
					for (int j=1;j<=n;j++)
						if (c[j]<=mid&&~b[j]&1&&!fl[b[i]+b[j]])
							add(i,j,inf);
				}
				else add(i,T,a[i]);
			}
		while (bfs()) flow-=dfs(S,inf);
		if (flow>=k) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
}
