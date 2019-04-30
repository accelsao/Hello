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
const int N=1e6+1;
const int M=1e9+7;
int b[N];
int main(){Accel
    int n,k;
    cin>>n>>k;k=n*(n-1)/2-k;
    vector<int>p(n);
    int t=0;
    for(int i=2;t<n;i++)
        if(!b[i]){
            if(i>=5)
                p[t++]=i;
            for(int j=i*2;j<N;j+=i)b[j]=1;
        }
    for(t=1;t*(t-1)/2<=k;t++);
    t--;
    REP(i,t)p[i]*=2;
    k-=(t-1)*t/2;
    REP(i,k)p[i]*=3;
    p[t]*=3;
    REP(i,n)cout<<p[i]<<" ";
    
    
            
    
}
