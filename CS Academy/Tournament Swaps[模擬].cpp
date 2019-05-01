#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
using namespace std;
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
const int N=20;
const int M=1e9+7;
int dp[N];
int n,a[1<<N];
int main(){Accel
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>dp(N,1<<n);
        FOR(i,1,1<<n)cin>>a[i];
        FOR(i,1,n)
            for(int j=1;j<=(1<<n);j+=1<<i){
                int f=0,s=0;
                FOR(k,j,j+(1<<i)-1){
                    s=max(s,min(a[k],f));
                    f=max(f,a[k]);
                }
                dp[i]=min(dp[i],s);
            }
        FOR(i,1,(1<<n))
			FOR(j,1,n+1)
			    if(dp[j]>=i){cout<<j-1<<" ";break;}
	    puts("");
    }
}
