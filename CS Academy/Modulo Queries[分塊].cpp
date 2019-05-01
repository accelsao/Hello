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
const int N=4e4+11;
const int M=4e4;
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
const int sz=650;
int n,q;
int a[N];
int b[N][N/sz+1];
int first_to_last[N<<1];
int main(){Accel
    cin>>n>>q;
    REP(i,n)cin>>a[i];
    int idx=0;
    for(int i=0;i<n;i+=sz){
        Re(first_to_last,0);
        int tn=min(i+sz,n);
        for(int j=i;j<tn;j++)
            first_to_last[a[j]]=a[j];
        for(int j=1;j<=(M<<1);j++)
            if(first_to_last[j]==0)
                first_to_last[j]=first_to_last[j-1];
        for(int mod=2;mod<=M;mod++){
            for(int k=mod;;k+=mod){
                if(b[mod][idx]<first_to_last[k-1]-k+mod){
                    b[mod][idx]=first_to_last[k-1]-k+mod;
                }
                if(k>M)break;
            }
        }
        idx++;
    }
    REP(i,q){
        int l,r,x;
        cin>>l>>r>>x;
        l--,r--;
        if(x==1){
            cout<<0<<endl;
            continue;
        }
        int ans=0;
        while(l%sz&&l<=r){
            ans=max(ans,a[l++]%x);
        }
        while(l+sz-1<=r){
            ans=max(ans,b[x][l/sz]);
            l+=sz;
        }
        while(l<=r){
            ans=max(ans,a[l++]%x);
        }
        cout<<ans<<endl;
    }
   
}
