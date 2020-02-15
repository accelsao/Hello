#include <bits/stdc++.h>
using namespace std;

// Suffix Array
template<typename T>
vector<int> suffix_array(int n, const T& s, int char_bound=-1) {
  vector<int> SA(n);
  if(n == 0) {
    return SA;
  }
  assert(n>0);
  if (char_bound != -1) {
    vector<int> aux(char_bound);
    for(int i = 0; i < n; i++) {
      aux[s[i]]++;
    }
    int sum = 0;
    for(int i = 0; i < char_bound; i++) {
      int add = aux[i];
      aux[i] = sum;
      sum += add;
    }
    for(int i = 0; i < n; i++) {
      SA[aux[s[i]]++] = i;
    }
  } else {
    iota(SA.begin(), SA.end(), 0);
    sort(SA.begin(), SA.end(), [&s](int i, int j) { return s[i] < s[j]; });
  }

  vector<int> group(n);
  vector<int> new_group(n);
  vector<int> ptr_group(n);
  vector<int> sorted_by_second(n);
  for(int i = 1; i < n; i++) {
    group[SA[i]] = group[SA[i - 1]] + (s[SA[i]] != s[SA[i - 1]]);
  }
  int cnt = group[SA[n - 1]] + 1;
  int step = 1;
  while(cnt < n) {
    int j = 0;
    for(int i = n - step; i < n;  i++) {
      sorted_by_second[j++] = i;
    }
    for(int i = 0; i < n; i++) {
      if(SA[i] >= step) {
        sorted_by_second[j++] = SA[i] - step;
      }
    }

    for(int i = n - 1; i >= 0; i--) {
      ptr_group[group[SA[i]]] = i;
    }

    for(int i = 0; i < n; i++) {
      int x = sorted_by_second[i];
      SA[ptr_group[group[x]]++] = x;
    }

    new_group[SA[0]] = 0;
    for(int i = 1; i < n; i++) {
      if(group[SA[i]] != group[SA[i - 1]]) {
        new_group[SA[i]] = new_group[SA[i - 1]] + 1;
      } else {
        int pre = (SA[i - 1] + step < n) ? group[SA[i - 1] + step] : -1;
        int cur = (SA[i] + step < n) ? group[SA[i] + step] : -1;
        new_group[SA[i]] = new_group[SA[i - 1]] + (pre != cur);
      }
    }
    swap(group, new_group);
    cnt = group[SA[n - 1]] + 1;
    step <<= 1;
  }
  return SA;
}

template<typename T>
vector<int> suffix_array(const T& s, int char_bound) {
  return suffix_array((int)s.size(), s, char_bound);
}

template<typename T>
vector<int> build_lcp(int n, const T& s, const vector<int>& sa) {
  // sa[i] = start index of sorted suffixes
  assert((int) sa.size() == n);
  assert(n > 0);
  if(n == 1){
    return {0};
  }
  // pos[i] = rank of str[i:]
  vector<int> pos(n);
  for(int i = 0; i < n; i++) {
    pos[sa[i]] = i;
  }
  int k = 0;
  vector<int> lcp(n - 1);
  for(int i = 0; i < n; i++) {
    k = max(k - 1, 0);
    if (pos[i] == n - 1){
      k = 0;
    } else {
      int j = sa[pos[i] + 1];
      while(i + k < n && j + k < n && s[i + k] == s[j + k]){
        k++;
      }
      lcp[pos[i]] = k;
    }
  }
  return lcp;
}

template <typename T>
vector<int> build_lcp(const T &s, const vector<int> &sa) {
  return build_lcp((int) s.size(), s, sa);
}

// Test
int main(){
  string s = "abcaabcac";
  int n = s.size();
  auto sa = suffix_array<string>(n, s, 256);
  auto lcp = build_lcp(s, sa);
  auto sa_ans = {3, 0, 4, 7, 1, 5, 8, 2, 6};
  auto lcp_ans = {1, 4, 1, 0, 3, 0, 1, 2};
  assert(equal(sa.begin(), sa.end(), sa_ans.begin()));
  assert(equal(lcp.begin(), lcp.end(), lcp_ans.begin()));
  puts("PASS");
}

//  Note

//  string: abcaabcac

//  aabcac
//  abcaabcac
//  abcac
//  ac
//  bcaabcac
//  bcac
//  c
//  caabcac
//  cac

// [suffix_array]: {3, 0, 4, 7, 1, 5, 8, 2, 6}
// [lcp]: {1, 4, 1, 0, 3, 0, 1, 2}

