#include <bits/stdc++.h>

using namespace std;
const int N=1e4+1;
int x,n;
vector<int>d[N];
int sm(int a,int b){
    printf("Q %d %d\n",a,b);
    //fflush(stdout);
    cin>>x;return x==a;
}
int find(int l,int r){
    if(l==r)return l;
    int m=(l+r)>>1;
    int a=find(l,m);
    int b=find(m+1,r);
    if(sm(a,b)){
        d[a].push_back(b);
        return a;
    }
    else{
        d[b].push_back(a);
        return b;
    }
}
int main() {
    cin>>n;
    int f=find(1,n);
    int sd=d[f].back();d[f].pop_back();
    for(auto x:d[f])
        if(sm(x,sd))
            sd=x;
    printf("A %d",sd);
    //fflush(stdout);
    
}
