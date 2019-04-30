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
const int N=1<<18;
const int M=1e9+7;
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
int n,q;
string s;
LL d[N];
int c[N];
int main(){Accel
    cin>>n>>q;
    REP(i,q){
        cin>>s;
        int mask=0;
        REP(j,SZ(s)){
            if(s[j]=='1')mask+=1<<j;
        }
        c[mask]++;
    }
    REP(j,n){
        FOR(i,1,(1<<n)-1){
            if(i&(1<<j)){
                c[i]+=c[i^(1<<j)];
            }
        }
    }
    //REP(i,1<<n)cout<<c[i]<<" ";
    //cout<<endl;
    REP(i,n)d[1<<i]=c[1<<i]&1;
    //cout<<d[1]<<d[2];
    REP(i,1<<n){
        if(d[i]){
            REP(j,n){
                //cout<<(i^(1<<j))<<" "<<i<<endl;
                //cout<<c[i^(1<<j)]<<" "<<c[i]<<endl;
                if((!(i&(1<<j)))&&(c[i^(1<<j)]-c[i])%2==0){
                    //cout<<i<<endl;
                    d[i^(1<<j)]+=d[i];
                }
            }
        }
    }
    cout<<d[(1<<n)-1]<<endl;
}
/*
1,2,4,8,2^n
考慮由小到大依次放入
101
1的位置表示放的東西會影響此筆詢問的值
從1開始放
REP(i,n)d[1<<i]=c[1<<i]&1;
對於只有1個1的mask 只要query odd 就有1
mask從前一個轉移
Ex:
10110 從10010轉移  10010 (2個1 代表已經考慮了 1,2)
10110現在要求這個 所以要考慮放入4的情況
因為 10110 10010  考慮這位置10'1'10 放入4 對於所有query 第3位置是1的 考慮奇偶 (因為這種query的第3位置放入當前最大:4 結果max一定是>1 所以要偶數次才
不會影響結果)


*/
