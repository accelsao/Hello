#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)-1;
int n,dp[N],x;
int main(){
    for(int i=0;i<N;i++)
        dp[i]=N;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        dp[x]=x;
    }
    int ans=1;
    for(int i=N-1;i>0;i--){
        if(dp[i]==i)ans++;
        int t=i;
        while(t){
            dp[i^(t&-t)]&=dp[i];
            t-=t&-t;
        }
    }
    cout<<ans<<endl;
}
