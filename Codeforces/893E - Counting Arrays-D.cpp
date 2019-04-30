#include<iostream>
using namespace std;
#define LL long long 
const LL M = 1e9 + 7,N=2e6+1;
LL f[N] = {1,1},ans,s,t,x,y,c;
LL pw(LL a, LL b) { return b ? b & 1 ? a*pw(a, b - 1) % M : pw(a*a%M, b >> 1) : 1; }
int main() {
	for (int i = 2; i <= N; i++)f[i] = f[i - 1] * i%M;
	cin>>t;
	while (t--) {
		cin>>x>>y;y--;
		ans=pw(2,y);
		for (int i = 2; i*i <= x; i++) {		
			c = 0;
			while (x%i == 0)c++, x /= i;
			if (c)(ans *= f[c + y] * pw(f[c] * f[y] % M, M - 2)%M)%=M;
		}
		if (x > 1)
			ans = ans*(y + 1) % M;
		cout<<ans<<endl;
	}
}
