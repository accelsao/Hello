// �i�i�i�������������������������������������������������������������������������i
// �i�i�i���i�i�i�i�i�i�i�������������������������������i�i�i���������i�����������i
// �i�i�i�i�i�i�i���i�i�i�i�i�����������������������i�i�i�������������������������i
// �i�i�i�i���������������i�i�i�i�i������������i�i�i����������������������������i
// �i�i�i�����������������������i�i�����������������������������������������������i
// �i�i�i�i�����������������������i�����������������������������������������������i
// �i�i�i���i���i�i�i�i�i�i�i�����i�i�i�����������������i�i�i�i�i�i�i�������������i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i���i������������������������������������������i
// �i�i�i�����������������������������i�������������������������������������������i
// �i�i�i�i���������������������������i�������������������������������������������i
// �i�i�i���i���������������������������������������������������������������������i
// �i�i�i�i�i�����������������i�������i�������������������������������������������i
// �i�i�i�i�i���������������i�i�������i����������������������������������������i�i
// �i�i�i�i�i�����������i�i�i�i�������i����������������������������������������i�i
// �i�i�i�i���i���������i�i���������i�i����������������������������������������i�i
// �i�i�i�i�����i�i�i���������������i�i��������������������������i�������������i�i
// �i�i�i�i�i���i�i�i�����������������i�i�i�i������������������i���������������i�i
// �i�i�i�i�i�����i���i�i�i�������i�i�i�i�����i���������������i��������������i�i�i
// �i�i�i�i�i�i���i�i���i�i�i�i�i�i�i�������������������i�i�������������������i�i�i
// �i�i�i�i�i�i�i���i�i����������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�����i�i���������������������������������������������������i�i�i�i
// �i�i�i�i�i�i�i�i�������i�i�i�i�i���������������������������������������i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�������i�����������i�i�i���������������������������i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�������i�����������i�i�������������������������i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�����i���������i�i�i�����������������������i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�i��������������������i�i�i�i�i�i�i�i�i�i
// �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�������i�i�������������������i�i�i�i�i�i�i�i�i�i�i
#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
const int N = 1e6 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;

int n, m;
set<int> g[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int u, v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	set<int> s;
	for(int i=1;i<=n;i++)
		s.insert(s.end(), i);
	int ans=0;
	
	while(s.size()){
		ans++;
		queue<int> q;
		q.push(*s.begin());
		s.erase(s.begin());
		while(q.size()){
			int u=q.front();q.pop();
			auto it=s.begin();
			while(it!=s.end()){
				if(g[u].find(*it)==g[u].end()){
					q.push(*it);
					it = s.erase(it);
				}
				else{
					it++;
				}
			}
		}
	}
	printf("%d\n", ans-1);
	
	
	
//	set<int> s;
//	for(int i=1;i<=n;i++){
//		p[i]=i;
//		R[i]=1;
//	}
//	for(int i=1;i<=n;i++){
//		for(const int& j:g[i]){
//			a[find(j)]++;
//		}
//		for(auto it=s.begin();it!=s.end();){
//			if(R[*it]>a[*it]){
//				R[i]+=R[*it];
//				R[*it]=0;
//				p[*it]=i;
//				
//				a[*it]=0;
//				it=s.erase(it);
//			}
//			else{
//				it++;
//			}
//		}
//
//		s.insert(s.end(), i);
////		for(const auto& x:s)
////			printf("%d ",x);puts("");
//	}
//	printf("%d\n", s.size()-1);
////	int ans=0;
////	for(int i=1;i<=n;i++)
////		if(find(i)==i){
////			ans++;
////		}
////	printf("%d\n", ans-1);
////	cout<<ans-1<<"\n";
//	
}




