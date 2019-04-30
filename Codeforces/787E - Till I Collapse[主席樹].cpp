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
const int N=1e5+1;
const int M=1e9+7;
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
int n,a[N];
int pre[N];
int root[N];
int tot;
struct Node{
	int l,r,sum;
}tree[N*40];
int update(int las,int l,int r,int pos,int v){
	int num=++tot;
	tree[num]=tree[las];
	tree[num].sum+=v;
	if(l==r)return num;
	int m=l+r>>1;
	if(pos<=m)
		tree[num].l=update(tree[las].l,l,m,pos,v);
	else
		tree[num].r=update(tree[las].r,m+1,r,pos,v);
	return num;
}
int find(int x,int l,int r,int k){
	if(l==r)return l;
	int m=l+r>>1;
	if(tree[tree[x].l].sum>=k)return find(tree[x].l,l,m,k);
	return find(tree[x].r,m+1,r,k-tree[tree[x].l].sum);
}
int main(){Accel
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	for(int i=n;i;i--){
		int num=root[i+1];
		if(pre[a[i]])num=update(num,1,n,pre[a[i]],-1);
		root[i]=update(num,1,n,i,1);
		pre[a[i]]=i;
	}
	FOR(i,1,n){
		int now=1,ans=1;
		while(tree[root[now]].sum>i){
			now=find(root[now],1,n,i+1);
			ans++;
		}
		cout<<ans<<" ";
	}
}
