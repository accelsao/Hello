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
const int N=400000+1;
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
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int n;
LL w[N];
int f[N][21];
LL g[N][21];
int main(){Accel
	cin>>n;
	int last=0,cnt=1;
	w[0]=1e18;
	FOR(i,0,20)g[1][i]=1e18;
	REP(i,n){
		LL t,p,q;
		cin>>t>>p>>q;
		p^=last,q^=last;
		if(t==1){
			w[++cnt]=q;
			if(w[p]>=w[cnt]){
				f[cnt][0]=p;
			}
			else{
				for(int i=20;~i;i--){
					if(w[f[p][i]]<w[cnt]){
						p=f[p][i];
					}
				}
				f[cnt][0]=f[p][0];
			}
			g[cnt][0]=f[cnt][0]?w[f[cnt][0]]:1e18;
			for(int i=1;i<=20;i++){
				f[cnt][i]=f[f[cnt][i-1]][i-1];
				g[cnt][i]=f[cnt][i]?g[cnt][i-1]+g[f[cnt][i-1]][i-1]:1e18;
			}
		}
		else {
			if(w[p]>q){
				cout<<0<<endl;
				last=0;
				continue;
			}
			q-=w[p];
			int tot=1;
			for(int i=20;~i;i--)
				if(g[p][i]<=q){
					q-=g[p][i];
					tot+=1<<i;
					p=f[p][i];
				}

			cout<<tot<<endl;
			last=tot;
		}
	}
}
