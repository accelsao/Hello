#include <iostream>
using namespace std;
const int M=1e9+7;
int n, now, i, p[5001];
char c;

int main() {
	now=1;
	p[now] = 1;
	cin>>n;
	while(n--) {
		cin >> c;
		if (c == 'f') now++;
		else 
			for (int i=1; i<=now; i++)
				p[i]=(p[i]+p[i-1])%M;
	}
	cout<<p[now];
}
