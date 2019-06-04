#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


class RMQ {
public:
	RMQ(const vector<int>& arr) {
		int n = static_cast<int>(arr.size());
		int m = static_cast<int>(log2(n)) + 1;
		st.resize(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			st[i][0] = arr[i];
		for (int k = 1; k < m; k++) {
			for (int i = 0; i + (1 << k) - 1 < n; i++) {

				st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
				
			}
		}
		log2k.resize(n+1, 0);	
		for (int i = 2; i <= n; i++) {
			log2k[i] = log2k[i / 2] + 1;
		}
	}
	int get(int l, int r) {
		int len = r - l + 1;
		int k = log2k[len];
		return min(st[l][k], st[r - (1 << k) + 1][k]);
	}
private:
	vector<vector<int>> st;
	vector<int> log2k;
};

int main() {
	int n = 100;
	vector<int> arr(100);
	for (int i = 0; i < 100; i++)
		arr[i] = i;
	RMQ rmq(arr);
	cout << rmq.get(2, 6) << endl;
}