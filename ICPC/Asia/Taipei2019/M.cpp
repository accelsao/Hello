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
const int N = 16234567;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;
ll pw(ll a, ll b, int M){ll t=1;a%=M;for(;b;b>>=1){if(b&1){t=t*a%M;}a=a*a%M;}return t;}
ll gcd(ll a, ll b){return b?gcd(b, a%b): a;}

struct Solver{
	vector<ll> perm;
	int p, d, pd;
	Solver()=default;
	Solver(int _p, int _d):p(_p), d(_d){
		pd=1;
		for(int i=0;i<d;i++)pd*=p;
		perm.resize(pd);
		perm[0]=1;
		for(int i=1;i<pd;i++){
			if(i%p==0)perm[i]=perm[i-1];
			else perm[i] = perm[i-1] * i % pd;
		}
	}
	ll V(ll m){ //count a => (m!) % p^a == 0
		if(!m)return 0;
		return m / p + V(m/p);
	}
	ll f(ll m){
		if(!m)return 1;
		ll ans=f(m/p) * perm[m%pd] % pd;
		ans = ans * pw(perm[pd-1], m/pd, pd) % pd;
		return ans;
	}
};

map<int, Solver> solver;
map<int, ll> vp;

template<class T>
tuple<T, T, T> exGcd(T a, T b){
	if(!b)return make_tuple(a, 1, 0);
	T gcd, x, y;
	T k = a / b;
	tie(gcd, x, y)=exGcd(b, a - k * b);
	return make_tuple(gcd, y, x - k * y);
}	

int Inv(int a, int b){
	assert(__gcd(a, b)==1);
	//ax+by=gcd(a,b)=1
	//ax=1-by
	//ax=1 (%=b) shows that x is modular multiplicative inverse of a
	int gcd, x, y;
	tie(gcd, x, y) = exGcd(a, b);
	int ans = (x%b+b)%b;
	assert(1LL*ans*a%b==1);
	return ans;

}

ll CRT(vector<ll>mod, vector<ll>a){
	
	ll lcm=mod[0];
	ll ans=a[0];
	for(int i=1;i<SZ(a);i++){
		ll gcd, x, y;
		tie(gcd, x, y) = exGcd(lcm, mod[i]);
		if((a[i]-ans)%gcd!=0)return -1;
		ll k = (x * (a[i]-ans) / gcd)  % (mod[i] / gcd) * lcm;
		lcm = mod[i] / gcd * lcm; //update new_lcm= LCM(mod[i], last_lcm)
		ans = ((ans + k) % lcm + lcm) % lcm;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	
	ll m, n, d;
	cin>>m>>n>>d;
	int _d=d;
	vector<pii> pd;
	for(int i=2;i<=d;i++){
		if(d%i==0){
			int cnt=0;
			while(d%i==0){
				cnt++;
				d/=i;
			}
			pd.emplace_back(i, cnt);
		}
	}
	
	ll k=INF;
	for(auto it: pd){
		solver[it.F] = Solver(it.F, it.S);
		ll pm=solver[it.F].V(m);
		ll pn=solver[it.F].V(n);
		ll pmn=solver[it.F].V(m-n);
		ll t=pm-pn-pmn;
		assert(t>=0);
		vp[it.F]=t;
		k=min(k, t/it.S);
	}
	vector<ll> mod, prime;
	for(auto it: pd){
		ll fm = solver[it.F].f(m);
        ll fn = solver[it.F].f(n);
        ll fmn = solver[it.F].f(m - n);
        int pdd= solver[it.F].pd;
        
//        printf("%lld %lld %lld %d\n", fm, fn, fmn, pdd);
        
        fm=1LL*fm*Inv(fn, pdd)%pdd*Inv(fmn, pdd)%pdd;
        
//        printf("fm: %lld\n", fm);
        
        ll a=it.S;
        ll b=vp[it.F]-a*k;
		mod.PB(pdd);
		
        if(b>=a){
        	prime.PB(0);
        	
		}
		else{
			ll pb=1;
			for(int i=0;i<b;i++){
				pb=pb*it.F;
				
			}
			assert(_d%pdd==0);
			pb = pb * fm % pdd * Inv(pw(_d/pdd, k, pdd), pdd) % pdd;//C(m,n) / pdd 
			prime.PB(pb);
		}
	}
//	for(auto x: mod)
//		printf("mod: %lld, ", x);
//	cout<<"\n";
//	for(auto x: prime)
//		printf("prime: %lld, ", x);
//	cout<<"\n";
	
	printf("%lld\n", CRT(mod, prime));
}

/*
#ifdef DEBUG
	cout<<"I Love Co shu Nie [ https://coshunie.com/ ]"
#endif

9 2 3
5 2 5
6 3 6
7654321 1234567 1050

*/



