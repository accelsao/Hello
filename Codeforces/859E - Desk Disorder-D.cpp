#include<iostream>
using namespace std;
const int N = 1e6;
const int M = 1e9 + 7;
#define LL long long
int n, x, y, p[N], r[N], k[N], t = 1;
int find(int x){
	return x == p[x] ? x : p[x] = find(p[x]);
}
int main(){
	cin >> n;
	for (int i = 0; i <= n * 2; i++)p[i] = i, r[i] = 1;
	for (int i = 0; i < n; i++){
		cin >> x >> y; k[x] = 1;
		if (x == y)continue;
		int a = find(x), b = find(y);
		if (a == b)t = t * 2 % M;
		r[b] += r[a]; 
		p[a] = b;
	}
	for (int i = 1; i <= n * 2; i++)
		if (!k[i])
			t = 1LL * t*r[i] % M;
	cout << t << endl;
}
