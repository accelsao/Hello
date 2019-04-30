#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

bool led[N];
vector<int>DAG[N];
int in[N],vis[N],ans[N];
int n,k,m,f;
void dfs(int u){
    vis[u]=1;
    for(auto v:DAG[u])
        if(vis[v]){
            if(vis[v]==1){
                f=1;
                return ;
            }
        }
        else dfs(v);
    vis[u]=2;
}
bool cy(){
    for(int i=0;i<k;i++)vis[i]=0;
    f=0;
    for(int i=0;i<k;i++){
        if(vis[i])continue;
        dfs(i);
        if(f)return 1;
    }
    return 0;
}
int main(){
    cin>>n>>k>>m;
    vector<vector<int>>p(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(auto &j:p[i])
            cin>>j;
        led[p[i][0]]=1;
    }
    for(int i=0;i<n-1;i++){
        int j=0;
        while(j<m&&p[i][j]==p[i+1][j])
            j++;
        if(j==m)  return puts("-1"),0;  
        DAG[p[i][j]].push_back(p[i+1][j]);
        in[p[i+1][j]]++;
    }
    if(cy())
        return puts("-1"),0;
    queue<int>q;
    for(int i=0;i<k;i++)
        if(!in[i])q.push(i);
    int ze=0,num=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto i:DAG[u]){
            in[i]--;
            if(!in[i])q.push(i);
        }
        if(!ze&&!led[u]){
            ans[u]=0;
            ze=1;
            continue;
        }
        ans[u]=num++;
    }
    if(!ze)puts("-1");
    else{
        for(int i=0;i<k;i++)
            cout<<ans[i]<<' ';
        puts("");
    }
}
