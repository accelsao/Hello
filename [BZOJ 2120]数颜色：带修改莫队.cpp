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
const int N=1e4+5;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
int n,m;
int a[N],b[N],vis[N],num[N*100],pos[N];
struct op1{
	int pos,x,y;
}ch[N];
struct op2{
	int p,l,r,id;
}q[N];
bool cmp(op2 a,op2 b){
	return pos[a.l]==pos[b.l]?a.r<b.r:pos[a.l]<pos[b.l];
}
int tot,cnt,ans,res[N];
int l=1,r=0,now=0;
void update(int x){//pos
	//cout<<vis[x]<<" "<<a[x]<<" "<<ans<<endl; 
	if(vis[x]){
		if(!--num[a[x]])ans--;
	}
	else{
		if(++num[a[x]]==1)ans++;
	}
	vis[x]^=1;
}
void change(int pos,int y){
	if(vis[pos]){ 
		update(pos);
		a[pos]=y;
		update(pos);
	}
	else a[pos]=y;
}
void solve(){
	FOR(i,1,cnt){
		for(int j=now+1;j<=q[i].p;j++)
			change(ch[j].pos,ch[j].y);
		for(int j=now;j>q[i].p;j--) 
			change(ch[j].pos,ch[j].x);
		while(r<q[i].r)update(++r);
		while(r>q[i].r)update(r--);
		while(l<q[i].l)update(l++);
		while(l>q[i].l)update(--l);
		res[q[i].id]=ans;
		now=q[i].p;
	}
}
int main(){Accel
	cin>>n>>m;
	int t=sqrt(n);
	FOR(i,1,n){
		cin>>a[i];
		b[i]=a[i];
		pos[i]=(i-1)/t+1;
	}
	FOR(i,1,m){
		char c;
		int x,y;
		cin>>c>>x>>y;
		if(c=='R'){
			ch[++tot]=op1{x,b[x],y};
			b[x]=y;
		}
		else q[++cnt]=op2{tot,x,y,cnt};
	}
	sort(q+1,q+1+cnt,cmp);
	solve();
	FOR(i,1,cnt)
		cout<<res[i]<<endl;
}
