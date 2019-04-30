#include<bits/stdc++.h>
using namespace std;
const int N = 2505;
int k, n,dif[N],twin[N];
string s[N];
map<char, int>m[N];
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++){
		cin >> s[i];
		for (auto x : s[i])
			if (++m[i][x] > 1)twin[i] = 1;
		if (m[i] != m[0])return puts("-1"), 0;
	}
	for (int i = 1; i < k; i++)
		for (int j = 0; j < n; j++)
			dif[i] += (s[0][j] != s[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
    		    bool f=0;
    			for (int d = 1; d < k; d++){
    				int lef = dif[d] - (s[0][i] != s[d][i]) + (s[0][i] != s[d][j]) - (s[0][j] != s[d][j]) + (s[0][j] != s[d][i]);
    				if (lef>2 || (!lef&&!twin[d])){f=1;break;}
        		}
        		if(!f){
        			swap(s[0][i], s[0][j]);
        			cout << s[0] << endl;
        			return 0;
        		}
			}
	puts("-1");
}
