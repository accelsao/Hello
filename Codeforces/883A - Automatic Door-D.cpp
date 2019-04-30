#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL d, p[100001], ans, t, pre, l, n, m, a, len, ct;
int main() {
	cin >> n >> m >> a >> d;//employee,client,employee time,door time
	t = d / a + 1;//開一次門可以讓幾個employee過去
	for (int i = 0; i < m; i++) cin >> p[i];
	sort(p, p + m);
	for (int i = 0; i < m; i++) {
		if (p[i] <= pre)continue;
		l = min(p[i] / a, n);//client 之前最後出現的employee num
		len = l - min(pre / a, n);//上次和這次之間經過多少employee  相差幾個employee
		ans += (len + t - 1) / t;//len/t  相差的employee/開一次過幾個人= 要開幾次門 有多的len%t!=0 再多開一次
		if (len)//a*(l+1) a*(l-扣掉多的人) 如果剛好整除就扣掉t 相當於扣掉整個單位的人數
			pre = a*(l - (len%t ? len%t : t) + 1) + d;//d 開門時間 期間都不會再需要開門
		
		if (p[i] > pre)pre = p[i] + d, ans++;//開門期間 客戶沒進來 再開一次門
	}
	len = n - min(pre / a, n);//客人都沒 還有employee的情況
	ans += (len + t - 1) / t;
	cout << ans;
}
//note that employee come at a*i(1<=i<=n) moment
//find client and door relative with employee

#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,a,d,x, ans, t, pre, l,r,len;
int main() {
	cin >> n >> m >> a >> d;
	t = d / a + 1;
	for (int i = 0; i < m; i++) {
		cin>>x;
		if (x <= pre)continue;
		r = min(x / a, n);
		len = r-min(pre/a,n);
		ans += (len + t - 1) / t;
		if(len)
			pre = a*(r - (len%t ? len%t : t) + 1) + d;
		if (x > pre)pre = x + d, ans++;
	}
	len = n - min(pre / a, n);
	ans += (len + t - 1) / t;
	cout << ans;
}
