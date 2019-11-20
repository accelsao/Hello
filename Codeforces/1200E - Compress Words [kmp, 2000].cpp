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


vector<int> get_pi(const string& s){
	int n=s.size();
	vector<int> pi(n);
	int j=0;
	for(int i=1;i<n;i++){
		while(j>0&&s[i]!=s[j]){
			j=pi[j-1];
		}
		if(s[i]==s[j]){
			j++;
		}
		pi[i]=j;
	}
	return pi;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s, p;
	cin>>p;
	for(int i=1;i<n;i++){
		cin>>s;
		auto pi=get_pi(s);
		int k=0;
		for(int j=max(0, int(p.size()-s.size()));j<p.size();j++){
			while(k>0&&p[j]!=s[k]){
				k=pi[k-1];
			}
			if(p[j]==s[k]){
				k++;
			}
		}
		p+=s.substr(k);
	}
	cout<<p<<"\n";	
}
/*
3
abdd bddt dt8
*/

