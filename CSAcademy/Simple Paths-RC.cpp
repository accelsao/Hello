#include <bits/stdc++.h>

using namespace std;
const int N=1001;
int v[N],s,t,c,con[N],concnt,isbridge[N][N],p[N];
vector<int>g[N];
pair<int,int>rem;
void dfs(int u){
    con[u]=concnt;
    for(auto x:g[u])
        if(!con[x])
            dfs(x);
}
void bridge(int u){
    v[u]=1;
    for(auto x:g[u]){
        if(v[x])continue;
        if(u==rem.first&&x==rem.second)continue;
        if(u==rem.second&&x==rem.first)continue;
        //cout<<x<<endl;
        bridge(x);
    }
        
}
int check(int x,int y){
    queue<int>q;
    memset(v,0,sizeof v);
    q.push(x);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto x:g[u]){
            if(v[x])continue;
            v[x]=1;
            p[x]=u;
            
            q.push(x);
        }
    }
    for(int i=y;i!=x;i=p[i]){
        if(!isbridge[p[i]][i])return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,q,x,y;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        
    }
   for(int i=1;i<=n;i++){
       if(con[i])continue;
       concnt++;
       dfs(i);
       
   }
   for(int i=1;i<=n;i++){
        for(auto j:g[i]){
            rem={i,j};
            memset(v,0,sizeof(v));
            int contmp=0;
            for(int k=1;k<=n;k++){
                if(v[k])continue;
                contmp++;
                bridge(k);
                //cout<<k<<endl;
            }
            //cout<<contmp<<' '<<concnt<<endl;
            if(contmp>concnt)
                isbridge[i][j]=1;
       }
   }
  // for(int i=1;i<=n;i++)
   // for(int j=1;j<=n;j++)
    //    if(isbridge[i][j])cout<<i<<' '<<j<<endl;
    while(q--){
        cin>>s>>t;
       if(con[s]!=con[t])puts("0");
       cout<<check(s,t)<<endl;
        //puts("");
    }
}
