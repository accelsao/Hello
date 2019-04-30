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
const int N=1e5;
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
int q;
vector<int>bit[N+1];
void upd(int k,int p,int v){
	while(p*k<=N){
		bit[k][p]+=v;
		p+=p&-p;
	}
}
int get(int k,int p){
	p=min(p,N);
	p/=k;
	int s=0;
	while(p>=1){
		s+=bit[k][p];
		p-=p&-p;
	}
	return s;
}
int main(){Accel
	FOR(i,1,N)bit[i].resize(N/i+5);
	
	cin>>q;
	int t,x,k,s;
	REP(tm,q){
		cin>>t;
		if(t==1){
			cin>>x;
			for(int i=1;i*i<=x;i++){
				if(x%i==0){
					upd(i,x/i,1);
					if(x/i!=i)upd(x/i,i,1);
				}
			}
		}
		else{
			cin>>x>>k>>s;
			if(x%k||x>=s){
				cout<<-1<<endl;continue;
			}
			int L=1,R=s-x;
			if(get(k,R)==0){
				cout<<-1<<endl;continue;
			}
			int cur=0;
			for(int i=16;~i;i--){
				int l=cur,r=cur+(1<<i)-1;
				int B=x>>i&1;
				if(!B)
					l+=(1<<i),r+=(1<<i);
				l=max(l,L);
				r=min(r,R);	
				if(l<=r&&get(k,l-1)!=get(k,r)){
					if(!B)
						cur+=1<<i;
				}
				else{
					if(B)cur+=1<<i;
				}
			}
			cout<<cur<<endl;
		}
	}
}
