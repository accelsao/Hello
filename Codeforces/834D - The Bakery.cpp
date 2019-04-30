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
const int N=35001;
const int M=1e9+7;
const double eps=1e-6;
int a[N];
int pos[N],lst[N],lz[N*4],mx[N*4];
int dp[N];
void build(int rt,int l,int r){
	lz[rt]=0;
	if(l==r){mx[rt]=dp[l-1];return;}
	int m=l+r>>1;
	build(rt<<1,l,m);build(rt<<1|1,m+1,r);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
void pd(int rt,int l,int r){
	int &w=lz[rt];
	lz[rt<<1]+=w;
	lz[rt<<1|1]+=w;
	mx[rt<<1]+=w;
	mx[rt<<1|1]+=w;
	w=0;
}
void add(int rt,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		mx[rt]++;lz[rt]++;
		return;
	}
	if(lz[rt])pd(rt,l,r);
	int m=l+r>>1;
	if(L<=m)add(rt<<1,l,m,L,R);
	if(m<R)add(rt<<1|1,m+1,r,L,R);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
int find(int rt,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return mx[rt];
	}
	int ans=0;
	int m=l+r>>1;
	if(lz[rt])pd(rt,l,r);
	if(L<=m)ans=max(ans,find(rt<<1,l,m,L,R));
	if(m<R)ans=max(ans,find(rt<<1|1,m+1,r,L,R));
	return ans;
}
int main(){Accel
	int n,k,x;
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i],pos[i]=lst[a[i]],lst[a[i]]=i;
	FOR(i,1,k){
		build(1,1,n);
		FOR(j,1,n){
			add(1,1,n,pos[j]+1,j);
			dp[j]=find(1,1,n,1,j);
		}
	}
	cout<<dp[n]<<endl;
	
}
//
#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
using namespace std;
const int N=35001;
int n,k;
LL dp[N][2],ans;
int a[N],c[N];
int le=1,ri;
void add(int l,int r){
	while(le<l)ans-=!--c[a[le++]];
	while(le>l)ans+=!c[a[--le]]++;
	while(ri>r)ans-=!--c[a[ri--]];
	while(ri<r)ans+=!c[a[++ri]]++;
}
void cal(int k,int from,int to,int l,int r){
	if(l>r)return;
	int m=l+r>>1,best;
	LL &tmp=dp[m][k&1]=0;
	FOR(i,from,min(to,m)){
		add(i,m);
		if(ans+dp[i-1][!(k&1)]>tmp){
			tmp=ans+dp[i-1][!(k&1)];
			best=i;
		}
	}
	dp[m][k&1]=tmp;
	cal(k,from,best,l,m-1);
	cal(k,best,to,m+1,r);
}
int main(){Accel
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)add(1,i),dp[i][1]=ans;
	FOR(i,2,k)cal(i,1,n,1,n);
	cout<<dp[n][k&1]<<endl;
}
