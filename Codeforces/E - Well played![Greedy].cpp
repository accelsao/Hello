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
//const double eps=1e-6;
//typedef complex<double>C;
//const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
const int N=1234567;
const int M=1e9+7;
int n,a,b;
struct A{
	LL hp,dg,df;
};
bool cmp(const A &r,const A &h){
	return r.df>h.df;
}
int main(){Accel
	cin>>n>>a>>b;
	vector<A>v(n);
	LL k=1<<a;
	REP(i,n){
		cin>>v[i].hp>>v[i].dg;
		v[i].df=v[i].hp-v[i].dg;
	}
	sort(ALL(v),cmp);
	LL ans=0;
	REP(i,n){
		A t=v[i];
		if(i<b)
			ans+=max(t.hp,t.dg);
		else ans+=t.dg;
	}
	if(!b){
		cout<<ans<<endl;return 0;
	}
	LL res=0,tmp=ans;
	REP(i,n){
		A t=v[i];
		ans=tmp;
		//cout<<ans<<endl;
		if(i<b){
			ans+=max(t.hp*k-t.dg,0LL);
			//cout<<t.hp*k-t.dg<<endl;
			ans-=max(t.hp-t.dg,0LL);
		}
		else{
			ans+=max(t.hp*k-t.dg,0LL);
			ans-=max(v[b-1].hp-v[b-1].dg,0LL);
		}
		//cout<<ans<<endl;
		res=max(res,ans);
	}
	cout<<res<<endl;	
}
