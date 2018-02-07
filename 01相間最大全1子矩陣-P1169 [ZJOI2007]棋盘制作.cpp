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
using namespace std;
const int N=2001;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
int n,m;
int p[N][N];
int f[N][N];
int w[N];
int a1,a2;
void work(int x){
	FOR(i,1,n) 
		FOR(j,1,m)
			if(p[i][j]==x)
				f[i][j]=f[i-1][j]+1;
			else f[i][j]=0;
	FOR(i,1,n){
		stack<int>s,w;
		FOR(j,1,m+1){
			int mw=j;
			while(s.size()&&s.top()>f[i][j]){
				int hh=s.top(),ww=j-w.top();
				int lc=min(hh,ww);
				a1=max(a1,lc*lc);
				a2=max(a2,hh*ww);
				mw=w.top();
				w.pop(),s.pop();
			}
			s.push(f[i][j]);
			w.push(mw);
		}
	}
}
int main(){Accel
	cin>>n>>m;
	FOR(i,1,n)FOR(j,1,m){
		cin>>p[i][j];
		if((i+j)&1)p[i][j]=!p[i][j];
	}
	work(0);
	work(1);
	cout<<a1<<endl<<a2<<endl;
}
