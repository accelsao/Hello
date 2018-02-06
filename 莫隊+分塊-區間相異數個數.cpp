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
const int N=200000+1;
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
int a[N],ans,le=1,ri=0;
int c[1000001],k;

struct Ask{
	int l,r,k,id;
};
bool cmp(Ask a,Ask b){
	return a.k!=b.k?a.k<b.k:a.r<b.r;
}
int A[200000+10];
int main(){Accel
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int q;
	cin>>q;
	vector<Ask>Q;
	int k=sqrt(n);
	REP(i,q){
		int l,r,ky;
		cin>>l>>r;
		ky=(l-1)/k;
		Q.PB(Ask{l,r,ky,i});
	}
	sort(ALL(Q),cmp);
	vector<int>A(q+1);
	REP(i,q){
		int l=Q[i].l,r=Q[i].r;
		while(le<l)ans-=!--c[a[le++]];
		while(le>l)ans+=!c[a[--le]]++;
		while(ri<r)ans+=!c[a[++ri]]++;
		while(ri>r)ans-=!--c[a[ri--]];
		A[Q[i].id]=ans;
	}
	REP(i,q)cout<<A[i]<<endl;
}
