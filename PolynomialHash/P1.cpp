#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
using ull = unsigned long long;
const int N = 2e3 + 50;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;

int gen_base(const int before, const int after) {
//	cout<<"123\n";
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
//	default_random_engine mt_rand(seed);
    int base = uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

struct PolyHash{
	inline int diff(int a,int b){
		return (a-=b) < 0 ? a + mod : a;
	}
	static const int mod = (int)1e9 + 123;
	static int base;
	static vector<int> pow1;
	static vector<ull> pow2;
	
	vector<int> pref1;
	vector<ull> pref2;
	PolyHash(const string& s){
		assert(base<mod);
		const int n=s.size();
		pref1.resize(n + 1, 0);
		pref2.resize(n + 1, 0);
		
		while((int)pow1.size()<=n){
			pow1.push_back(1LL * pow1.back() * base % mod);
			pow2.push_back(pow2.back() * base);		
		}
		
		for(int i=0;i<n;i++){
			assert(s[i] < base);
			pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
			pref2[i+1] = pref2[i] + s[i] * pow2[i];
		}
		
	}
	inline pair<int, ull> operator()(const int& pos, const int& len, const int& max_pos=0)const{
		int hash1 = pref1[pos+len]-pref1[pos];
		ull hash2 = pref2[pos+len]-pref2[pos];
		if(hash1 < 0){
			hash1 += mod;
		}
		if(max_pos > 0){
			hash1 = 1LL * hash1 * pow1[max_pos - (pos+len-1)] % mod;
			hash2 = hash2 * pow2[max_pos - (pos+len-1)];
		}
		return {hash1, hash2};
	}	
};

int PolyHash::base = (int)1e9+7;
vector<int> PolyHash::pow1{1};
vector<ull> PolyHash::pow2{1};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a, b;
	cin>>a>>b;
	if(a.size()<b.size())swap(a, b);
	//a>=b
	PolyHash::base = gen_base(256, PolyHash::mod);
	PolyHash hash_a(a), hash_b(b);
	int max_len = a.size();
	const auto B = hash_b(0, b.size(), max_len);
	for(int i=0;i+b.size()<=a.size();i++){
		if(hash_a(i, b.size(), max_len) == B){
			printf("%d ", i);
		}
	}
	
}
/*
input:
abgggcfgcd
gcd
output:
1
*/

