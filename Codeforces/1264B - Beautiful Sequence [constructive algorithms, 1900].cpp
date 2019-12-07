#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define RE(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define SZ(x) ((int)(x.size()))
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using C = complex<double>;
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<int> a(4);
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	for(int rot=0;rot<2;rot++){
		vector<int> b=a;
		int even=a[0]+a[2];
		int odd=a[1]+a[3];
		if(even==odd||even==odd+1){
			int n=a[0]+a[1]+a[2]+a[3];
			vector<int> d(n, -1);
			for(int i=0;i<n;i+=2){
				if(a[0]>0){
					a[0]--;
					d[i]=0;
				}
				else if(a[2]>0){
					a[2]--;
					d[i]=2;
				}
			}
//				d[i]=a[0]>0?0, a[0]--:2, a[2]--;
			for(int i=1;i<n;i+=2){
				if(a[1]>0){
					a[1]--;
					d[i]=1;
				}
				else if(a[3]>0){
					a[3]--;
					d[i]=3;
				}
			}
//				d[i]=a[1]>0?1, a[1]--:3, a[3]--;
			bool ok=1;
			for(int i=1;i<n;i++){
				ok&=abs(d[i]-d[i-1])==1;
				ok&=d[i]>-1;
			}
			if(ok){
				cout<<"YES\n";
				for(int i=0;i<n;i++){
					if(!rot)
						cout<<d[i]<<" ";
					else
						cout<<3-d[i]<<" ";
				}
				cout<<"\n";
				return 0;
			}
		}
		a=b;
		reverse(ALL(a));
		
		
	}
	cout<<"NO\n";
	
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif
*/

