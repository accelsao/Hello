/*
input : 
	two string a,b
output:
	a*b 
time complexity:
	nlog(n)
*/ 
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
const double PI(acos(-1.0));
typedef complex<double> C;
const int N = (1 << 20);
//Bigint multiply 
//FFT
//O(N logN loglogN)
int ans[N];
C a[N], b[N];
string s,t;
void FFT(C* a, int n, int t) {
  	// bit-reversal permutation 
	for (int i=1, j=0; i<n; ++i){
    	for (int k=n>>1; k>(j^=k); k>>=1) ;
    	if (i<j) swap(a[i], a[j]);
    }
	for (int k = 2; k <= n; k <<= 1) {
		double g=2.0*t*PI/k;
	    C dw(cos(g),sin(g));
	    for (int j = 0; j < n; j += k) {
	    	C w(1);
	    	for (int i = j; i < j + k/2; i++) {
		      	C x=a[i],y=a[i+k/2]*w;
		        a[i] = x+y;
		        a[i + k/2] =x-y;
		        w *= dw;
	      	}
	    }
  	}
  	//逆FFT 除n 
	if (t == -1) 
		REP(i,n)a[i] /= n;
}

int trans(int x) {
  return 1 << int(ceil(log(x) / log(2) - 1e-9));  // math.h/log() 以e?底
}

int main() {
	int n, m, l;
	while(cin>>s>>t){
	    n =s.size(),m =t.size();
	    l = trans(n + m - 1);  //至多n+m-1次
	    REP(i,n)a[i] = C(s[n - 1 - i] - '0');
	    for (int i = n; i < l; i++) a[i] = C(0);
	    REP(i,m)b[i] = C(t[m - 1 - i] - '0');
	    for (int i = m; i < l; i++) b[i] = C(0);
	    FFT(a, l, 1); 
	    FFT(b, l, 1);
	    REP(i,l)a[i] *= b[i];
	    FFT(a, l, -1);  //逆
	    REP(i,l) ans[i] = (int)(a[i].real() + 0.5);
	    ans[l] = 0;  // error-prone :'l' -> '1'
	    REP(i,l){
	      ans[i + 1] += ans[i] / 10;
	      ans[i] %= 10;
	    }
	    int p = l;
	    while(p&&!ans[p])p--;
	    while(~p)
	    	putchar(ans[p--]+'0');
	    cout<<endl;
	}
}
