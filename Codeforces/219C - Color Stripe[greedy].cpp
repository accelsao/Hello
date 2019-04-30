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
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
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
int n,k;
int main(){Accel
	cin>>n>>k;
	string s;cin>>s;
	int c=0,n=SZ(s);
	if(k>2){
		for(int i=1;i<n-1;i++){
			if(s[i]==s[i-1]){
				int l=s[i]-'A',r;
				r=(l+1)%3;
				if(r==s[i+1]-'A')r=(r+1)%3;
				c++;
				s[i]='A'+r;
			}
		}
		if(s[n-1]==s[n-2]){
			s[n-1]='A'+(((s[n-2]-'A')+1)%3);
			c++;
		}
		cout<<c<<endl;
		cout<<s<<endl;
	}
	else{
		string A="",B="";
		int ca=0,cb=0,t=0;
		REP(i,n){
			if(s[i]!='A'+t)ca++;
			else cb++;
			
			A+='A'+t;
			B+='A'+!t;t^=1;
		}
		if(ca<cb){
			cout<<ca<<endl;
			cout<<A<<endl;
		}
		else{
			cout<<cb<<endl;
			cout<<B<<endl;
		}
	}
}
