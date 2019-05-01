#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m;
const int M=1e9+7;
int main() {
    cin>>n>>m;
    LL ans=0;
    for(LL i=1;i<=min(n,m);i++)
        ans=(ans+i*(n+1-i)*(m+1-i))%M;
        
    cout<<ans<<endl;
}
