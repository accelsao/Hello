#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
using pii = pair<int,int>;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;

vector<pii> gen_won(int pts){
	vector<pii> ans;
	for(int i=0;i<=pts-2;i++){
		ans.push_back({pts, i});
	}
	for(int i=pts+1;i<=200;i++){
		ans.push_back({i, i-2});
	}
	return ans;
}
vector<pii> dp[4][4][234][234];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	
	for(int s1=0;s1<3;s1++)
		for(int s2=0;s2<3;s2++){
			int pts=(s1+s2==4)?15:25;
			vector<pii> won = gen_won(pts);
			for(int a=0;a<=200;a++)
				for(int b=0;b<=200;b++){
					if(!dp[s1][s2][a][b].empty()||(s1+s2+a+b==0)){
						for(const pii& x:won){
							int na=a+x.F;
							int nb=b+x.S;
							if(na<=200&&nb<=200&&dp[s1+1][s2][na][nb].empty()){
								dp[s1+1][s2][na][nb]=dp[s1][s2][a][b];
								dp[s1+1][s2][na][nb].push_back(x);
							}
							na=a+x.S;
							nb=b+x.F;
							if(na<=200&&nb<=200&&dp[s1][s2+1][na][nb].empty()){
								dp[s1][s2+1][na][nb]=dp[s1][s2][a][b];
								dp[s1][s2+1][na][nb].push_back({x.S, x.F});
							}
						}
					}
				}
		}
	int T;
	cin>>T;
	int a, b;
	while(T--){
		cin>>a>>b;
		bool f=0;
		vector<pii> ans;
		int s1=-1, s2=10;
		for(int i=0;i<=2;i++){
			if(dp[3][i][a][b].size()&&3-i>s1-s2){
				ans=dp[3][i][a][b];
				s1=3,s2=i;
			}
			if(dp[i][3][a][b].size()&&i-3>s1-s2){
				ans=dp[i][3][a][b];
				s1=i,s2=3;
			}
		}
		if(s1==-1){
			printf("Impossible\n");
		}
		else{
			printf("%d:%d\n",s1,s2);
			for(const pii& x:ans){
				printf("%d:%d ", x.F,x.S);
			}
			printf("\n");
		}
		
	}
}
/*
1
50 50


*/

