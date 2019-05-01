#include <bits/stdc++.h>

using namespace std;
const int N=1e5+1;
const int M=1e9+1;
int p[N];
vector<pair<int,int>>q,v;
int main() {
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
        cin>>p[i],q.push_back({p[i]-i,i});
    v.push_back({M,0});
    for(int i=0;i<n;i++)
        if(q[i]>v.back())
            v.push_back(q[i]);
        else
            *lower_bound(v.begin(),v.end(),q[i])=q[i];
    cout<<n-v.size()<<endl;
}
