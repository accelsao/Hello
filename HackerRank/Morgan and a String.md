# Problem
給你兩個字串 每次可以從任一字串挑選第一個字元然後加入新字串S
希望S的字典序越小越好

# Solution
假設兩字串有K個相同字第K+1個不同 我們挑選第K+1的字中最小的會比較好
為了減少比較 我們做出他們的SuffixArray 就可以快速計算兩字串的大小
構建新字串 = A + 'a' + B + 'a' (因為字元範圍A-Z) 選擇任一字元 > 所有可能字元

Notes: 用bucketsort才可過, 一般quicksort會timeout

# Code
```cpp
#include <bits/stdc++.h>
using namespace std;
vector<int> getSA(const string &s) {
    const int N = 2e5+100;
    int n = s.size();
    int alp_s = 52; // alphbet size
    vector<int> cnt(N);
    vector<int> sa(N);
    vector<int> rank(N);
    vector<int> new_rank(N);
    vector<int> sa_2(N);

  for (int i = 0; i < alp_s; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    rank[i] = s[i] - 'A';
    cnt[rank[i]]++;
  }
  for (int i = 1; i < alp_s; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    sa[--cnt[rank[i]]] = i;
  }

  for (int j = 1; j < n; j <<= 1) {

    for (int i = 0; i < alp_s; i++)
      cnt[i] = 0;
    for (int i = 0; i < n; i++)
      cnt[rank[i]]++;
    for (int i = 1; i < alp_s; i++)
      cnt[i] += cnt[i - 1];

    //sa_2.clear();
    int r = 0;
    for (int i = n - j; i < n; i++) {
      sa_2[r++] = i;
    }
    for (int i = 0; i < n; i++)
      if (sa[i] >= j) {
        sa_2[r++] = sa[i] - j;
      }

    for (int i = n - 1; i >= 0; i--) {
      sa[--cnt[rank[sa_2[i]]]] = sa_2[i];
    }

    new_rank[sa[0]] = r = 0;
    for (int i = 1; i < n; i++) {
        int p1 = (sa[i-1]+j)%n;
        int p2 = (sa[i]+j)%n;
      if (rank[sa[i - 1]] != rank[sa[i]] || rank[p1] != rank[p2])
        r++;
      new_rank[sa[i]] = r;
    }
    for(int i=0; i<n; i++)
        rank[i] = new_rank[i];

    if (r == n - 1)
      break;
    alp_s = r + 1;
  }

  return vector<int>(rank.begin(), rank.begin()+n);
}

string morganAndString(const string &a, const string &b) {
  string ab = a + 'b' + b + 'a';
  vector<int> SA = getSA(ab);

  int i = 0, j = 0;
  string ans = "";
    while(1){
        if(i >= a.size() && j >= b.size()){
            break;
        }
        if(i >= a.size()){
            ans += b[j++];
        }
        else if(j >= b.size()){
            ans += a[i++];
        }
        else{
            if(SA[i] < SA[j + a.size() + 1]){
              ans += a[i++];
            }else{
              ans += b[j++];
            }
            
        }
    }
    return ans;

}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    string ans = morganAndString(a, b);
    cout << ans << endl;
  }
}

/*
1
JACK
DANIEL

ABACABA
ABACABA

*/

```


