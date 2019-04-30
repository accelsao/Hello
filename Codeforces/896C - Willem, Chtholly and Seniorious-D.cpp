#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define LL long long
int n, m, vmx, op, l, r, y, x, seed;
int rnd() { int s = seed; seed = (1LL * seed * 7 + 13) % 1000000007; return s; }
LL pw(LL a, LL b) { return b ? b & 1 ? a*pw(a, b - 1) % y : pw(a*a%y, b >> 1) : 1; }
map<int, LL>mp;
vector<pair<LL, int>>v;
int main() {
	cin >> n >> m >> seed >> vmx;
	for (int i = 1; i <= n; i++)
		mp[i] = rnd() % vmx + 1;
	mp[n + 1] = 0;
	while (m--) {
		op = rnd() % 4 + 1;
		l = rnd() % n + 1, r = rnd() % n + 1;
		if (l > r)swap(l, r);r++;
		if (op == 3)x = rnd() % (r - l) + 1;
		else x = rnd() % vmx + 1;
		if (op == 4)y = rnd() % vmx + 1;
		auto L = --mp.upper_bound(l);//map[a]=[b] a=左界b=值  找最後一個<=l的左界
		if (L->first != l)mp[l] = L->second, L++;//因為區間都記錄左點 如果找到的數字小於l 就將左界mp[l]值 改成L的值 來計算
		auto R = --mp.upper_bound(r);
		if (R->first != r)mp[r] = R->second, R++;
		if (op == 1)
			while (L != R)L++->second += x;
		else if (op == 2)
			while (L != R)mp.erase(L++), mp[l] = x;
		else if (op == 3) {
			v.clear();
			for (int d; L != R;)
				d = R--->first, v.push_back({ R->second,d - R->first});
			sort(v.begin(), v.end());
			for (auto i : v)
				if (x <= i.second) { printf("%I64d\n", i.first); break; }
				else x -= i.second;
		}
		else {
			LL ans = 0;
			for (int d; L != R;)
				d = R--->first, (ans += pw(R->second%y, x)*(d - R->first)) %= y;
			printf("%I64d\n", ans);
		}
	}
}
/*
問題用map記錄 區間左界:區間的值
op 1 區間內都+X
op2 區間內刪掉 增加 mp[l]=x 代表整個區間都改成x 記錄左界 
區間大小兩相鄰map->first 相減
op=3
輸出第x小數字 區間一個一個減 把x當成需要跳過的數量 當前剩餘<=區間代表找到區間
op=4
輸出sum區間 每個值的x次方 所以要乘上區間長度 因為同數字都當成map[左界]記錄

R->second%y 一開始沒先mod 造成溢位 卡了整個下午(幹
*/
