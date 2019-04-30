#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m,k;
int x1,y1,x2,y2;
char p[N][N];
int dis[N][N];
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int bfs(){
	queue<pair<int,int>>q;
	q.push({x1,y1});
	dis[x1][y1]=0;
	while(q.size()){
		int u=q.front().first,v=q.front().second;q.pop();
		if(u==x2&&v==y2)return dis[x2][y2];
		for(int s=0;s<4;s++){
			int tu,tv;
			for(int w=1;w<=k;w++){
				tu=u+d[s][0]*w,tv=v+d[s][1]*w;
				if(tu<1||tu>n||tv<1||p[tu][tv]=='#'||tv>m||dis[u][v]>=dis[tu][tv])break;
				if(dis[tu][tv]>dis[u][v]+1){
					dis[tu][tv]=dis[u][v]+1;
					q.push({tu,tv});
				}
			}	
		}
	}
	return -1;

}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j],dis[i][j]=1e9;
	cin>>x1>>y1>>x2>>y2;
	cout<<bfs()<<endl;
}
