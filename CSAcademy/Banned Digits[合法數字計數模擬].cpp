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
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int t=0;while(x){t+=BIT[x];x-=x&-x;}return t;}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
#define int LL

int b[12],c[12];
LL n;
main(){Accel
	int can=0;
    REP(i,10)cin>>b[i];
    for(int i=9;i>=0;i--)
    	c[i]=c[i+1]+!b[i];
    cin>>n;
    string s=to_string(n);
    LL ans=0;
    int len=SZ(s);
    REP(i,len){
    	int num=s[i]-'0';
    	for(int j=0;j<num;j++){
    	    if(i+j==0)continue;
    	    if(!b[j]){
    	        LL z=1;
    	        for(int k=i+1;k<len;k++)
    	            z*=c[0];
    	       ans+=z;
    	    }
    	}
    	if(b[num]){
    	   break; 
    	}
    }
    //cout<<ans<<endl;
    LL z=c[1];
    for(int i=0;i<len-2;i++){
        
        ans+=z;
        z*=c[0];
       // cout<<ans<<endl;
    }
    ans+=z;
    //add 0
	cout<<ans+!b[0]<<endl;

}
