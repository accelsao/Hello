#include <bits/stdc++.h>

using namespace std;
int p[2001],dp[2001];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i];
    sort(p,p+n);
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--)
            if(p[j]%p[i]==0)
                dp[i]=max(dp[i],dp[j]+1);
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout<<ans+1<<endl;
}
