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
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
const int N=250;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
int n,m,k;
int p[N][N];
int f[N][N];
int g[N][N];
int h[N],w[N];
int get(int x1,int y1,int x2,int y2){
    return f[x2][y2]-f[x2][y1-1]-f[x1-1][y2]+f[x1-1][y1-1];
}
int main(){Accel
    cin>>n>>m>>k;
    int ans=0,z=0;
    FOR(i,1,n)
        FOR(j,1,m){
            cin>>p[i][j];
            z+=!p[i][j];
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+p[i][j];
        }
    FOR(i,1,n-k+1)
        FOR(j,1,m-k+1){
            g[i][j]=get(i,j,i+k-1,j+k-1);
            ans=max(ans,g[i][j]);
            h[i]=max(h[i],g[i][j]);
            w[j]=max(w[j],g[i][j]);
        }
    for(int i=n;i;i--)
        h[i]=max(h[i],h[i+1]);
    for(int i=m;i;i--)
        w[i]=max(w[i],w[i+1]);
    FOR(i,1,n-k+1)
        FOR(j,1,m-k+1){
            ans=max(ans,g[i][j]+max(h[i+k],w[j+k]));
        }
    FOR(i,1,n-k+1)
        FOR(j,1,m-k+1){
            FOR(ii,i,i+k-1)
                FOR(jj,j,j+k-1){
                    ans=max(ans,g[i][j]+g[ii][jj]-get(ii,jj,i+k-1,j+k-1));
                    if(jj>=k&&ii<=n-k+1){
                        ans=max(ans,g[i][j]+g[ii][jj-k+1]-get(ii,j,i+k-1,jj));
                    }
                }
            
            
        }
    cout<<ans+z<<endl;
}
