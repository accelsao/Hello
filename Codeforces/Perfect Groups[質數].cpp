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
const int N=1e4;
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
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int n;
int a[5001];
int c[5001];
bool vis[5001];
map<int,int>mp;
int main(){Accel
	cin>>n;
	FOR(i,1,n){
		int x;
		cin>>x;
		if(x){
			int s=x>0?1:-1,k=abs(x);
			x=abs(x);
			for(int j=2;j*j<=k;j++){
				if(x%j==0){
					int t=0;
					while(x%j==0)x/=j,t^=1;
					if(t)s*=j;
				}	
			}
			//cout<<s<<endl;
			a[i]=s*x;
			auto it=mp.lower_bound(a[i]);
			if(it==mp.end()||it->F!=a[i]){
				int sz=SZ(mp)+1;
				mp.insert(it,MP(a[i],sz));
				a[i]=sz;
			}
			else{
				a[i]=it->S;
			}
		}
		else{
			a[i]=0;
		}
		
		//cout<<a[i]<<endl;
	}
	
	FOR(i,1,n){
		int zero=0;
		int cnt=0;
		
		
		
		for(int j=i;j>=1;j--){
			if(a[j]==0)zero++;
			else if(!vis[a[j]]){
				cnt++;vis[a[j]]=1;
			}
			if(zero&&!cnt)c[1]++;
			else c[cnt]++;
		}
		FOR(j,1,i)vis[a[j]]=0;
	
	}
	FOR(i,1,n)
		cout<<c[i]<<" ";
		
	
}
