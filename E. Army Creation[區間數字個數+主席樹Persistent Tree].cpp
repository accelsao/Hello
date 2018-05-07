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
const int N=1e5+10;
const int M=1e9+7;

int n,k,ls;
int rt[N];
int a[N];
vector<int>v[N];
int tn;
struct A{
	int l,r,s;
}tr[N*20];
int add(int k,int l,int r,int x){
	int p=++tn,m=l+r>>1;
	tr[p].s=tr[k].s+1;
	if(l==r)return p;
	if(x<=m){
		tr[p].l=add(tr[k].l,l,m,x);
		tr[p].r=tr[k].r;
	}
	else{
		tr[p].l=tr[k].l;
		tr[p].r=add(tr[k].r,m+1,r,x);
	}
	return p;
}
int find(int k,int l,int r,int L,int R){
	if(l>=L&&r<=R)
		return tr[k].s;
	int m=l+r>>1;
	if(m>=R)return find(tr[k].l,l,m,L,R);
	if(m+1<=L)return find(tr[k].r,m+1,r,L,R);
	int s=0;
	s+=find(tr[k].l,l,m,L,R);
	s+=find(tr[k].r,m+1,r,L,R);
	return s;
}
int main(){Accel
	cin>>n>>k;
	FOR(i,1,n){
		rt[i]=rt[i-1];
		cin>>a[i];
		v[a[i]].PB(i);
		if(SZ(v[a[i]])>k)
			rt[i]=add(rt[i],1,n,v[a[i]][SZ(v[a[i]])-1-k]);
	}
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		l=(l+ls)%n+1;
		r=(r+ls)%n+1;
		
		if(l>r)swap(l,r);
		int ans=r-l+1-(find(rt[r],1,n,l,r)-find(rt[l-1],1,n,l,r));
		ls=ans;
		cout<<ls<<endl;
	}
	
} 
