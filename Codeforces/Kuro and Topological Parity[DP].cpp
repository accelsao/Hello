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
const int N=55;
const int M=1e9+7;
const double eps=1e-6;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
LL C[N][N];
LL cnt[N][2];
LL p2[N];
LL f[N][N][N];
int main(){Accel
	FOR(i,0,50){
		C[i][i]=C[i][0]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
		for(int j=0;j<=i;j++){
			cnt[i][j&1]+=C[i][j];
			cnt[i][j&1]%=M;
		}
	}
	p2[0]=1;
	FOR(i,1,50)
		p2[i]=p2[i-1]*2%M;
	f[0][0][0]=1;//node odd_black,odd_white
	int n,p;
	cin>>n>>p;
	LL way;
	FOR(i,1,n){
		int t;
		cin>>t;
		for(int j=0;j<i;j++){//black
			for(int k=0;j+k<i;k++){//white
				if(t==0||t==-1){//black
					//find white_even
					way=cnt[k][0]*p2[i-1-k]%M;
					f[i][j+1][k]+=f[i-1][j][k]*way%M;
					f[i][j+1][k]%=M;
					//white odd
					way=cnt[k][1]*p2[i-1-k]%M;
					f[i][j][k]+=f[i-1][j][k]*way%M;
					f[i][j][k]%=M;
				}
				if(t==1||t==-1){//white
					//find black_even
					way=cnt[j][0]*p2[i-1-j]%M;
					f[i][j][k+1]+=f[i-1][j][k]*way%M;
					f[i][j][k+1]%=M;
					//black odd
					way=cnt[j][1]*p2[i-1-j]%M;
					f[i][j][k]+=f[i-1][j][k]*way%M;
					f[i][j][k]%=M;
					
				}
			//	cout<<f[i][j][k]<<endl;
			}
		}
	}
	LL ans=0;
	FOR(i,0,n)
		for(int j=0;j+i<=n;j++){
			if((i+j)%2!=p)continue;
			//cout<<f[n][i][j]<<endl;
			ans+=f[n][i][j];
			ans%=M;
		}
	cout<<ans<<endl;
}
