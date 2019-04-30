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
//for(int mask=i;mask>0;mask=(mask-1)&i)-> bit,subset
//__gcd, atan2(y,x)=y/x , __int128
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
//cout<<fixed<<setprecision(12)<<ans<<endl;
int main(){Accel
    int n;
    cin>>n;
    vector<int>seg;
    vector<PII>line;
    FOR(i,1,n){
        int x,y;
        cin>>x>>y;
        line.PB(MP(x,y));
    }
    sort(ALL(line),[](PII a,PII b){return a.S<b.S;});
    LL s=1LL<<60;
    FOR(i,0,n-1){
        LL ans=0;
        int k=line[i].F;
        for(int j=i-1;j>=0;j--){
            
            ans+=k-line[j].S;
            k-=line[j].S-line[j].F;
        }
        k=line[i].S;
        for(int j=i+1;j<n;j++){
            ans+=line[j].F-k;
            k+=line[j].S-line[j].F;
        }
        s=min(s,ans);
    }
    cout<<s<<endl;
}
