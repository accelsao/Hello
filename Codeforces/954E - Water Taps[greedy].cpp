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
const int N=2e5+1;
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
//cout<<fixed<<setprecision(12)
int n,T;
LL a[N],t[N];
int main(){
	cin>>n>>T;
	long double tot=0;
	FOR(i,1,n){
		cin>>a[i];
		tot+=a[i];
	}
	vector<int>neg,pos;
	LL dif=0;
	double ans=tot;
	FOR(i,1,n){
		cin>>t[i];
		t[i]-=T;
		if(t[i]>=0)
			pos.PB(i);
		else neg.PB(i);
		dif+=a[i]*t[i];
	}
	if(dif==0){
		cout<<fixed<<setprecision(12)<<ans<<endl;return 0;
	}
	sort(ALL(pos),[](int a,int b){return t[a]>t[b];});
	sort(ALL(neg),[](int a,int b){return t[a]<t[b];});
	
	if(dif<0){
		for(auto i:neg)
			if(dif<t[i]*a[i]){
				tot-=a[i];
				dif-=t[i]*a[i];
			}
			else{
				//cout<<dif<<" "<<t[i]<<endl;
				ans=(long double)tot-(long double)dif/(long double)(t[i]);
				break;
			}
	}
	else{
		for(auto i:pos)
			if(dif>t[i]*a[i]){
				dif-=t[i]*a[i];
				tot-=a[i];
			}
			else{
				ans=(long double)tot-(long double)dif/(long double)t[i];
				break;
			}
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
}
