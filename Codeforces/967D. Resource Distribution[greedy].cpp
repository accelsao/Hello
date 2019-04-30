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
//const double eps=1e-6;
//typedef complex<double>C;
//const double PI(acos(-1.0));
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
//isalnum() decimal digit or an uppercase or lowercase letter
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
const int N=3e5+1;
struct A{
	int x,id;
	bool operator<(const A &a) const{
		return x>a.x;
	}
};
vector<A>p;
LL n,a,b;
bool cmp(A i,A j){
	return i.x>j.x;
}
bool sol(int ty){
	int i=0;
	while(i<n&&(a+p[i].x-1)/p[i].x>i+1)i++;
	if(i==n){
		return 0;
	}
	
	int j=i+1;
	while(j<n&&(b+p[j].x-1)/p[j].x>(j-i))j++;
	if(j==n){
		return 0 ;
	}
	cout<<"Yes\n";
	if(!ty){
		cout<<i+1<<" "<<j-i<<endl;
		for(int k=0;k<=i;k++)
			cout<<p[k].id<<" " ;
		cout<<endl;
		for(int k=i+1;k<=j;k++)
			cout<<p[k].id<<" ";
	}
	else{
		cout<<j-i<<" "<<i+1<<endl;
		
		for(int k=i+1;k<=j;k++)
			cout<<p[k].id<<" ";
		cout<<endl;
		for(int k=0;k<=i;k++)
			cout<<p[k].id<<" " ;
		cout<<endl;
		
	}
	return 1;
}
int main() {
	
	cin>>n>>a>>b;
	p.resize(n);
	REP(i,n)
		cin>>p[i].x,p[i].id=i+1;
	sort(ALL(p),cmp);
	bool f=sol(0);
	if(!f){
		swap(a,b);
		f=sol(1);
		if(!f)cout<<"No\n";
	}
}
