#include <iostream>
using namespace std;
int n, x, y,d[32010],dp[32010];
int lb(int n){
	return n&(-n);
}
int sum(int x){
	int t = 0;
	while (x)
		t += d[x], x-=lb(x);
	return t;
}
void add(int x){
	while (x < 32010)
		d[x]++, x += lb(x);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		dp[sum(++x)]++;
		add(x);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", dp[i]);
}
