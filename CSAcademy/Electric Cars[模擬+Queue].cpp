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
struct Car{
    int id,C,T;
    bool operator<(const Car& a)const{
        return id>a.id;
    }
};
LL ans[N];
int n;
int main(){Accel
    
    cin>>n;
    vector<Car>v(n);
    REP(i,n){
        cin>>v[i].C>>v[i].T;v[i].id=i;
    }
    sort(ALL(v),[](const Car& a,const Car& b){return a.T<b.T;});
    priority_queue<Car>q;
    int t=0;
    for(const auto& x:v){
        int ed=x.T;
        while(q.size()&&t!=ed){
            auto k=q.top();q.pop();
            int tmp=min(k.C,ed-t);
            //cout<<k.C<<" "<<ed-t<<endl;
            k.C-=tmp;
            t+=tmp;
            if(k.C==0){
                //cout<<t;
                ans[k.id]=t;
            }
            else q.push(k);
        }
        q.push(x);
        t=ed;
    }
    LL cur_t=t;
   //cout<<SZ(q);
    while(q.size()){
        auto k=q.top();q.pop();
        cur_t+=k.C;
        //cout<<cur_t<<endl;
        ans[k.id]=cur_t;
    }
    REP(i,n)
        cout<<ans[i]<<endl;
}
