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
const int N=2e5+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n;
int main(){Accel
   cin>>n;
   vector<int>v(n+2);
   FOR(i,1,n)cin>>v[i];
   v[n+1]=1<<30;
   v[0]=-v[n+1];
   vector<int>LIS(1);
   FOR(i,1,n+1)
       if(v[i]>v[LIS.back()])LIS.PB(i);
   if(LIS.size()==n+2)return cout<<n-1<<endl,0;
   int mxadd=0;
   for(int i=0;i+2<LIS.size();i++){
   		int p=v[LIS[i]];
        int add=-1;
        for(int j=LIS[i+1]+1;j<LIS[i+2];j++)
        	if(v[j]>p)p=v[j],add++;
        mxadd=max(mxadd,add);  
   }
   cout<<LIS.size()-2+mxadd<<endl;
}
