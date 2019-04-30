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
//watch out LL
int n;
int a[N];
int main(){
	cin>>n;
	int w;
	int f=0;
	FOR(i,1,n){
		cin>>a[i];
		
		if(i>1){
			if(a[i]==a[i-1]){
				cout<<"NO\n";
				return 0;
			}
			else{
				w=abs(a[i]-a[i-1]);
				if(w!=1)f=w;
			}
		}
	}
	if(n==1||!f){
		cout<<"YES\n";
		cout<<1<<" "<<M-7<<endl;
		return 0;
	}
	//cout<<"151\n";
	w=f;
	//cout<<w<<endl;
	FOR(i,2,n){
		if(abs(a[i]-a[i-1])>=2){
			if(abs(a[i]-a[i-1])!=w){
				cout<<"NO\n";
				return 0;
			}
			
		}
		else{
			if((a[i-1]-1)/w!=(a[i]-1)/w){
				cout<<"NO\n";
				return 0;
			}
		}
	}
	
	
	cout<<"YES\n";
	if(~w){
		cout<<M-7<<" "<<w<<endl;
	}
	else{
		cout<<M-7<<" "<<M-7<<endl;
	}
}
