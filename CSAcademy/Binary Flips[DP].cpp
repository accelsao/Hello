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
const int N=1e6+1;
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
LL f[2][N];
int n,m,k,s;
int c,p;
void g(int n){
    c=0,p=1;
    Re(f,0);
    f[p][0]=1;
    FOR(i,1,k){
        FOR(j,0,n)f[c][j]=0;
        FOR(j,0,n){
            if(!f[p][j])continue;
            if(j)f[c][j-1]+=f[p][j]*j%M,f[c][j-1]%=M;
            f[c][j+1]+=f[p][j]*(n-j)%M,f[c][j+1]%=M;
        }
        swap(c,p);
    }
}
LL h[N],w[N];
int main(){Accel
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>s;
        
        g(n);
        FOR(j,0,n)h[j]=f[p][j];
        g(m);
        FOR(j,0,m)w[j]=f[p][j];
        LL ans=0;
        FOR(i,0,n)
            FOR(j,0,m){
                int cnt=n*m-i*j-(n-i)*(m-j);
                if(cnt==s){
                    ans=(ans+h[i]*w[j]%M)%M;
                }
                
            }
        cout<<ans<<endl;
    }
}
