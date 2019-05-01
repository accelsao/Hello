#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair <int, int> ii;

#define m2(x) ((x) * (x))
#define ms(a, w) memset(a, w, sizeof(a))
#define mc(a, b) memcpy(a, b, sizeof(b))
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

const int MAXN = 210;
const int MAXM = 1010;
const int MAX = 1010;
const int MOD = 1000000007;
const int INF = 1000000000;
const int _10[] = {0, 10, 100, 1000, 10000};

int f[MAXN][MAXN][MAXN >> 1][4];
string s;
int a[MAXN];

int main () {
	int n;
	cin >> n;
	cin >> s;
	for (int i = 1; i <= n; i++)
		f[i][i][a[i] = s[i - 1] - '0'][1] = 1;
	for (int i = 1; i < n; i++)
		if (a[i] == a[i + 1])
			f[i][i + 1][11 * a[i] % 101][2] = 1;
	for (int l = 0; l < n; l++)
		for (int i = 1, j; (j = i + l) <= n; i++) {
			for (int k = 0; k < 101; k++)
				for (int len = 0; len < 4; len++) {
					(f[i][j][k][len] += (f[i + 1][j][k][len] + f[i][j - 1][k][len]) % MOD) %= MOD;
					(f[i][j][k][len] += MOD - f[i + 1][j - 1][k][len]) %= MOD;
					if (i > 1 && j < n && a[i - 1] == a[j + 1])
						(f[i - 1][j + 1][(_10[len + 1] * a[i - 1] + k * 10 + a[i - 1]) % 101][(len + 2) % 4] += f[i][j][k][len]) %= MOD;
				}
			if (i > 1 && j < n && a[i - 1] == a[j + 1])
				(++f[i - 1][j + 1][11 * a[i - 1] % 101][2]) %= MOD;
		}
	int ans = 0;
	for (int len = 0; len < 4; len++)
		(ans += f[1][n][0][len]) %= MOD;
	cout << ans << endl;

	return 0;	
}
----my WA code
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
#define REP(I, A, B) for (int I = (A); I < (B); I++)
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
using namespace std;
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b >> 1,M) : 1; }
LL gcd(LL a, LL b) { return b ? gcd(b, a%b) : a; }
const int N=210;
const int M=1e9+7;
int dp[N][N][4][105];
int n,a[N],t[5]={0,10,100,1000,10000};
string s;
int main(){Accel
    cin>>n>>s;
    FOR(i,1,n)dp[i][i][1][a[i]=s[i-1]-'0']=1;
    for(int i=1;i<n;i++)
    	if(a[i]==a[i+1])
    		dp[i][i+1][2][a[i]*11%101]=1;
    for(int L=0;L<n;L++)
    	for(int i=1;;i++){
			int j=i+L;
			if(j>n)break;
			for (int k = 0; k < 101; k++){
				for (int len = 0; len < 4;len++){
					(dp[i][j][len][k]+=(dp[i+1][j][len][k]+dp[i][j-1][len][k])%M)%=M;
					(dp[i][j][len][k]+=M-dp[i+1][j-1][len][k])%=M;
					if(i>1&&j<n&&a[i-1]==a[j+1])
						(dp[i-1][j+1][(len+2)%4][(a[i-1]*t[len+1]+k*10+a[j+1])%101]+=dp[i][j][len][k])%=M;
				}
				if(i>1&&j<n&&a[i-1]==a[j+1])
					(++dp[i-1][j+1][2][11*a[i-1]%101])%=M;
			}	
		}
	int ans=0;
	for (int len = 0; len < 4;len++)
		(ans+=dp[1][n][len][0])%=M;
	cout<<ans<<endl;
}
	
