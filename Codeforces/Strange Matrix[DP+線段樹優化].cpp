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
const int N=5+1;
const int M=2e4+1;
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


int n,m,q;
int p[N][M];
int st[M*4][N][N];
int tmp[N][N];
void up(int rt){	
	FOR(i,1,n)FOR(j,1,n)tmp[i][j]=-1e9;
	int l=rt<<1,r=rt<<1|1;
	FOR(r1,1,n)
		FOR(r2,1,n)
			FOR(j,1,n)
				FOR(k,-1,1){
					if(j+k>=1&&j+k<=n){
						
						/*cout<<tmp[r1][r2]<<" ";
						cout<<st[l][r1][j]<<" ";
						cout<<st[r][j+k][r2]<<"\n";*/
						tmp[r1][r2]=max(tmp[r1][r2],st[l][r1][j]+st[r][j+k][r2]);
					}
				
				}
	FOR(r1,1,n)
		FOR(r2,1,n){
			st[rt][r1][r2]=tmp[r1][r2];
		}
	return ;
}
void build(int rt,int l,int r){
	if(l==r){
		FOR(i,1,n){
			st[rt][i][i]=p[i][l];
		}
		return ;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	up(rt);
}
void update(int rt,int l,int r,int pos){
	if(pos<l)return;
	if(pos>r)return;
	if(l==r){
		FOR(i,1,n)
			st[rt][i][i]=p[i][l];
		return ;
	}
	int mid=l+r>>1;
	update(rt<<1,l,mid,pos);
	update(rt<<1|1,mid+1,r,pos);
	up(rt);
}
int get(){
	int ans=0;
	FOR(r1,1,n){
		FOR(r2,1,n){
			ans=max(ans,st[1][r1][r2]);
		//	cout<<st[1][r1][r2] <<" ";
		}
		//cout<<endl;
	}
	return ans;
}
int main(){Accel
    cin>>n>>m>>q;
    FOR(i,1,n)
        FOR(j,1,m)
            cin>>p[i][j];
    FOR(k,1,m*4)FOR(i,1,n)FOR(j,1,n)st[k][i][j]=-1e9;
    build(1,1,m);
	
    while(q--){
		int r,c,x;
		cin>>r>>c>>x;
		p[r][c]=x;
		update(1,1,m,c);
		cout<<get()<<endl;
	}
    
}
