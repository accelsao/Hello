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
using namespace std;
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b >> 1,M) : 1; }
const int N=1e5+1;
const int M=1e9+7;
int n,p[N],c[N];
int a[N],b[N],mx;
int main(){Accel

    cin>>n;
    REP(i,n)cin>>a[i];
    REP(i,n){cin>>b[i],a[i]-=b[i];
        if(a[i]<0)return puts("-1"),0;
        mx=max(mx,b[i]);
    }
    int t=a[0];
    for(int i=1;i<n;i++)
            t=__gcd(t,a[i]);
            t=__gcd
    if(!t)return cout<<mx+1<<endl,0;
    vector<int>ans;
    for(int i=1;i*i<=t;i++)
        if(t%i==0)ans.PB(i),ans.PB(t/i);
    sort(ALL(ans));
    for(auto x:ans)
        if(x>mx)
            return cout<<x<<endl,0;
    puts("-1");
}
