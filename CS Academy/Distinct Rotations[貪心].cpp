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
string s;
int n;
bool f(int sz){
    //cout<<sz<<endl;
    string t=s;
    for(int i=0;i<sz;i++){
        char ls='?';
        for(int j=i;j<n;j+=sz){
            if(ls!='?'){
                if(s[j]!='?'&&s[j]!=ls)return 0;
            }
            else ls=s[j];
        }
        if(ls=='?')ls='0';
        //cout<<ls<<endl;
        //cout<<i<<" "<<n<<endl;
        for(int j=i;j<n;j+=sz){
            //cout<<j<<endl;
        
            t[j]=ls;
            
        }
    }
    //cout<<sz<<endl;
    cout<<t<<endl;
    return 1;
}
int main(){Accel
    cin>>s;
    n=SZ(s);
    for(int i=1;i<=n;i++)
        if(n%i==0){
            if(f(i)){
                return 0;
            }
        }
    /*for(auto x:s)
        if(x!='?')cout<<x;
        else cout<<"0";*/
}
