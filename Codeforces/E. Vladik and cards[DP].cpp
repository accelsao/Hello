#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define SZ(a) ((int)a.size())
using namespace std;
const int N=1e3+10;
const int S=1<<8;
int n;
int a[N];
int b[8][N];
int f[S][9];
int find(int v,int k){
	if(b[v][n]<k)return -1;
	return lower_bound(b[v],b[v]+n+1,k)-b[v];
}
bool solve(int x){
	int d=x/8;
	REP(s,1<<8)
		FOR(i,0,x%8)f[s][i]=n+1;
	f[0][0]=0;
	REP(s,S-1)
		FOR(i,0,x%8){
			if(f[s][i]>n)continue;
			REP(j,8){
				if(s>>j&1)continue;
				REP(x,2){
					int p=find(j,b[j][f[s][i]]+d+x);
					if(~p){
						f[s^(1<<j)][i+x]=min(f[s^(1<<j)][i+x],p);
					}
				}
			}
		}
	return f[S-1][x%8]<=n;
}
int main(){
	cin>>n;
	REP(i,n){
		cin>>a[i];
		a[i]--;
		REP(j,8)
			b[j][i+1]=b[j][i];
		b[a[i]][i+1]++;
	}
	int l=0,r=n,m;
	while(l<=r){
		m=l+r>>1;
		if(solve(m))l=m+1;
		else r=m-1;
	}
	cout<<l-1<<endl;

}
