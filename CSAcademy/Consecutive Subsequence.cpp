#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1;
int p[N],dp[N][2];
int n,m,ans;
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];p[i]++;
        dp[p[i]][0]=1+dp[p[i]-1][0];
        dp[p[i]][1]=max(dp[p[i]-1][1]+1,dp[p[i]-2][0]+2);
        m=max(m,p[i]+1);
    }
    for(int i=1;i<=m;i++)ans=max(ans,max(dp[i][0],dp[i][1]));
    cout<<ans<<endl;
}
