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
#define endl "\n"
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
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
int a,tmp,c=0;
LL l,r;
int main(){Accel
	cin>>a;
	int x=a,k=1;
	while(x%2){
		tmp+=(x%10)*k;
		c++;
		k*=10;
		x/=10;
	}
	if(!x){
		cout<<-1<<endl;return 0;
	}
	l=tmp+1;
	int c2=c;
	if(x%10==0){
		while((x/10)%2==1){
			if((x/10)%10==1&&x/100==0)break;
			c2++;
			l+=pow(10,c2);
			if((x/10)%10>1)break;
			x/=10;
		}
	}
	if(c)r=pow(10,c)-tmp+1;
	else r=1;
	while(c>1){
		c--;
		r+=pow(10,c);
	}
	cout<<l*r<<endl;
}
