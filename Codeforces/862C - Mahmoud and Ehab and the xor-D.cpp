#include <bits/stdc++.h>

using namespace std;
int n, k, t, p = 1 << 18;
set<int>s;
int main(){
	cin >> n >> k;
	if (n == 1)printf("YES\n%d\n", k);
	else if (n == 2){
		if (!k)puts("NO");
		else printf("YES\n%d %d\n", 0, k);
	}
	else{
		for (int i = 1; i <= n - 3; i++)t ^= i, s.insert(i);
		if (k == t)
			s.insert({ p, p << 1, p ^ p << 1 });
		else s.insert({ 0, p, p ^ k ^ t });
		puts("YES");
		for (auto x : s)
			printf("%d ", x);
	}
}
