#include <bits/stdc++.h>
#define ld long double
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
//typedef complex<double>C;
//const double PI(acos(-1.0));
//const double eps(1e-8);
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
const int N=2e5;
const int M=1e9+7;
const LL inf=1e15;
LL tr[N*4+50];
int n,A,B;
struct Point{
	int x,y,z;
	LL s,w;
}p[N+10];
LL f[N+10];
void update(int x,LL val,int rt=1,int l=1,int r=N){
	if(l==r){
		tr[rt]=val;
		return ;
	}
	int m=l+r>>1;
	if(x<=m){
		update(x,val,rt<<1,l,m);
	}
	else{
		update(x,val,rt<<1|1,m+1,r);
	}
	tr[rt]=max(tr[rt<<1],tr[rt<<1|1]);
}
void makeTree(){
	FOR(i,1,N*4-1)tr[i]=-inf;
}
bool cmp(Point a,Point b){
	return a.z<b.z;
}
LL find(int L,int R,int rt=1,int l=1,int r=N){
	if(l>=L&&r<=R){
		return tr[rt];
	}
	if(r<L||l>R)return -inf;
	int m=l+r>>1;
	return max(find(L,R,rt<<1,l,m),find(L,R,rt<<1|1,m+1,r));
}
void merge(int l,int r){
	int m=l+r>>1;
	vector<PII>left,right;
	FOR(i,l,m){
		left.PB(MP(p[i].x,p[i].z));
		
	}
	FOR(i,m+1,r){
		right.PB(MP(p[i].x,p[i].z));
	}
	sort(ALL(left));
	sort(ALL(right));
	int L=0,R=-1;
	for(auto u:right){
		int i=u.S;
		int x=u.F;
		while(R+1<SZ(left)&&left[R+1].F-x<=A){
			R++;
			int j=left[R].S;
			update(p[j].y,p[j].s);
		}
		while(L<SZ(left)&&x-left[L].F>A){
			int j=left[L].S;
			update(p[j].y,-inf);//-p[j].S
			L++;
		}
		p[i].s=max(p[i].s,p[i].w+find(max(1,p[i].y-B),min(N,p[i].y+B)));
	}
	while(L<=R){
		int j=left[L].S;
		update(p[j].y,-inf);
		L++;
	}
}
void solve(int l,int r){
	if(l==r){
		p[l].s=max(p[l].s,p[l].w);
		return ;
	}
	int m=l+r>>1;
	solve(l,m);
	merge(l,r);
	solve(m+1,r);
}
int main(){Accel
	
	cin>>n>>A>>B;
	REP(i,n){
		cin>>p[i].x>>p[i].y>>p[i].z>>p[i].w;
		p[i].s=-inf;
	}
	sort(p,p+n,cmp);
	REP(i,n){
		p[i].z=i;
	}
	solve(0,n-1);
	LL ans=0;
	REP(i,n)
		ans=max(ans,p[i].s);
	cout<<ans<<endl;
} 
