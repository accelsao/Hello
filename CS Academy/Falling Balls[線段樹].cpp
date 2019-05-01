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
const int M=1e6;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
//cout<<fixed<<setprecision(12)<<ans<<endl;


struct Node{
	int x1,x2,y;
	Node(){cin>>x1>>x2>>y;}
	bool operator<(const Node& a){
		return y<a.y;
	}
};
int tr[1<<20];
void build(int rt,int l,int r){
	if(l==r){
		tr[rt]=l;
		return ;
	}
	int m=l+r>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}
void add(int rt,int l,int r,int L,int R,int v){
	if(tr[rt]&&l!=r){
		tr[rt<<1]=tr[rt];
		tr[rt<<1|1]=tr[rt];
		tr[rt]=0;
	}
	if(l>=L&&r<=R){
		tr[rt]=v;
		return ;
	}
	int m=l+r>>1;
	if(L<=m)add(rt<<1,l,m,L,R,v);
	if(m<R)add(rt<<1|1,m+1,r,L,R,v);
}
int get(int rt,int l,int r,int pos){
	if(tr[rt]){
		return tr[rt];
	}
	int m=l+r>>1;
	if(pos<=m)
		return get(rt<<1,l,m,pos);
	else
		return get(rt<<1|1,m+1,r,pos);
}
int n,m;
int main(){Accel
	cin>>n>>m;
	vector<Node>p(n);
	sort(ALL(p));
	build(1,1,N);
	REP(i,n){
		int mid=(p[i].x1+p[i].x2)/2;
		add(1,1,N,p[i].x1,mid,get(1,1,N,p[i].x1));
		add(1,1,N,mid+1,p[i].x2,get(1,1,N,p[i].x2));
	}
	while(m--){
		int x;
		cin>>x;
		cout<<get(1,1,N,x)<<endl;
	}
}
