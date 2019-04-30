#include <iostream>
#include<set>
using namespace std;
int n, m, q, t, a, b, c, d, k;
struct B{
	int a, b, c, d;
	bool operator<(const B x)const{
		return a < x.a ? 1 : a == x.a&&b < x.b ? 1 : a == x.a&&b == x.b&&c < x.c ? 1 : a == x.a&&b == x.b&&c == x.c&&d < x.d ? 1 : 0;
	}
};
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> q;
	set < B > s;
	while (q--){
		cin >> t >> a >> b >> c >> d;
		if (t == 1)s.insert({ a, b, c, d });
		else if (t == 2)s.erase({ a, b, c, d });
		else{k = 0;
			for (auto i : s){
				
				k |= (i.a <= a&&a <= i.c&&i.b <= b&&b <= i.d) ^
					(i.a <= c&&c <= i.c&&i.b <= d&&d <= i.d);
			}
			puts(k?"No":"Yes");
		}
	}
}
