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

int main(){Accel
   int n;cin>>n;
   vector<PII>p(n);
   REP(i,n)
        cin>>p[i].F>>p[i].S;
    sort(ALL(p),[](PII a,PII b){return MP(a.S,a.F)<MP(b.S,b.F);});
    vector<PII>a;
    REP(i,n){
        while(SZ(a)){
            if(p[i].F-(p[i].S-a.back().S)>=a.back().F){
                a.pop_back();
            }
            else break;
        }
        if(SZ(a)){
            if(a.back().F-(p[i].S-a.back().S)>=p[i].F){
                
            }
            else a.PB(MP(p[i].F,p[i].S));
        }
        else a.PB(MP(p[i].F,p[i].S));
    }
    LL ans=0;
    for(auto x:a){
        ans+=1LL*x.F*x.F;
       // cout<<x.F<<endl;
    }
    for(int i=0;i+1<SZ(a);i++){
        auto x=a[i],y=a[i+1];
        if(y.S-x.S+1>=x.F+y.F)continue;
        int l=x.S;
        for(int i=29;~i;i--){
            int tmp=(1<<i)+l;
            if(x.F-(tmp-x.S)>=y.F-(y.S-tmp)){
                l=tmp;
            }
            //cout<<l<<endl;
        }
    //    cout<<x.S<<" "<<y.S<<" "<<l<<endl;
        int h=x.F-(l-x.S)-1;
        ans-=1LL*h*(h+1)/2;
        h=y.F-(y.S-l);
        ans-=1LL*h*(h+1)/2;
       // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
