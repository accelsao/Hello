# Prefix Doubling O(Nlog^2N)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
// log2(N) = 20
int suffixRank[20][N];

struct suffix {
	int idx; // index
	int l, r; // first half, second half
	bool operator<(const suffix& a)const {
		if (l == a.l)return r < a.r;
		return l < a.l;
	}
};

int main() {
	string s;
	cin >> s;
	int n = s.size();
	// Init
	for (int i = 0; i < n; i++) {
		suffixRank[0][i] = s[i] - 'a';
	}
	vector<suffix>sa(n);
	for (int j = 1; j < 20; j++) {
		int len = 1 << (j - 1);
		for (int i = 0; i < n; i++) {
			sa[i].idx = i;
			sa[i].l = suffixRank[j - 1][i];
			sa[i].r = i + len < n ? suffixRank[j - 1][i + len] : -1;
		}
		sort(sa.begin(), sa.end());
		suffixRank[j][sa[0].idx] = 0;
		int rank = 0;
		for (int i = 1; i < n; i++) {
			if (sa[i - 1].l != sa[i].l || sa[i - 1].r != sa[i].r) {
				++rank;
			}
			suffixRank[j][sa[i].idx] = rank;
		}

	}
	cout << "Origin String: ";
	cout << s << endl;
	for (int i = 0; i < n; i++) {
		string substr = s.substr(sa[i].idx);
		cout << "Rank " << i << ": " << substr << endl;
	}
	

}
/*
machinelearning
*/
```
# DC3 O(N)
[csdn](https://blog.csdn.net/hyforthy/article/details/17381087)
[gihub](https://github.com/8igMac/dc3/blob/master/dc3.cpp)