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
const int MAXN=1e5+1;
int N, M, K,c1,c2;
int main() {
	cin >> N >> M >> K;
	vector<vector<char>>S(N,vector<char>(M));
	REP(i,N)REP(j,M)cin >> S[i][j];
	vector<int>C;
	int cs=0,cM;//c1 total & c2-c1[mid]
	REP(j,(M+1)/2){
	    c1=c2=0;
	    REP(i,N){
		    c1+= (S[i][j] != S[i][M - 1 - j]);
		    if(i<(N+1)/2){
    			int ndiv = 1;
    			if (i == N - 1 - i) 
    				ndiv *= 2;
    			if (j == M - 1 - j) 
    				ndiv *= 2;
    			set<char>s;
    			map<char,int>mt;
    			s.insert(S[i][j]);mt[S[i][j]]++;
    			s.insert(S[N-1-i][j]);mt[S[N-1-i][j]]++;
    			s.insert(S[i][M-1-j]);mt[S[i][M-1-j]]++;
    			s.insert(S[N-1-i][M-1-j]);mt[S[N-1-i][M-1-j]]++;
    		    int most=0;
    			for(auto x:s)most=max(most,mt[x]);
    			c2+= (4 - most) / ndiv;
		    }
		}
		if (j != M - 1 - j) 
		   C.PB(c2-c1);
	    else 
		    cM=c2-c1;
        cs+=c1;
	}
    sort(ALL(C));
	//case 1: middle one is not used
    int ans=0;
    REP(i,(K+1)/2)ans+=C[i];
	//case 2: middle one is used and M is odd
	int tmp=0;
	REP(i,K/2)tmp+=C[i];
	if (M % 2) 
		ans = min(ans, tmp+ cM);
    cout<<ans+cs<<endl;
}
