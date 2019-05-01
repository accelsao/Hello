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
const int N=1e5+1;
const LL M=1e18+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int n;
int a[N];
int BIT[N];
void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
map<int,int>mp;
int gp;
vector<int>pos[N];
int find(int i,int j){
    if(i>j)swap(i,j);
    return sum(j-1)-sum(i-1);
}
int main(){Accel
    cin>>n;
    FOR(i,1,n){
        cin>>a[i];
        mp[a[i]]=1;
    }
    for(auto &x:mp)
        x.S=++gp;
    FOR(i,1,n){
        a[i]=mp[a[i]];
        pos[a[i]].PB(i);
    }
    pos[0].PB(1);
    LL f[2]={0,0};
    FOR(i,1,gp){
        for(auto j:pos[i]){
            add(j);
            
            
        }
        int pre[2]={pos[i-1].front(),pos[i-1].back()};
        int cur[2]={pos[i].front(),pos[i].back()};
        LL tmp[2]={M,M};
        
        
        
        REP(p,2)
            REP(c,2){
                tmp[c]=min(tmp[c],f[p]
                +abs(pre[p]-cur[c^1])-find(pre[p],cur[c^1])
                +abs(cur[c]-cur[c^1])-find(cur[c],cur[c^1])
                );
                if(i==4){
                   // cout<<+abs(pre[p]-cur[c^1])<<endl;
                    //cout<<pre[p]<<cur[c^1]<<endl;
                    //cout<<BIT[3]<<" "<<BIT[2]<<endl;
                    //cout<<find(pre[p],cur[c^1])<<endl;
                }
            }
        f[0]=tmp[0];
        f[1]=tmp[1];
        
       // cout<<f[0]<<endl;
       /// cout<<f[1]<<"\n\n";
        
    }
    cout<<min(f[0],f[1])+n<<endl;
}
