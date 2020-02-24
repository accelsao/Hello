// include and define
#include <bits/stdc++.h>
using namespace std;

// debug
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
//#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// debug


// assume size of vector is 32-bit
template <typename T>
struct WaveletTree {

  struct WaveletNode {
    size_t n;
    T lo, hi; // range of value
    vector<bool> B;
    vector<size_t> Bc;
    unique_ptr<WaveletNode> left, right;

    template <typename Iterator>
    WaveletNode(Iterator first, Iterator last, T _lo, T _hi) :
      n(distance(first, last)), lo(_lo), hi(_hi), B(n)
    {
      const T mid = lo + (hi - lo) / 2;
      for(size_t i = 0; i < n; i++) {
        B[i] = (first[i] > mid);
      }

      Bc.resize(n + 1);
      for(size_t i = 0; i < n; i++) {
        Bc[i + 1] = Bc[i] + (B[i] == 0);
      }

      if(lo < hi) {
        auto pivot = stable_partition(first, last, [mid](T x) { return x <= mid; });
        left = (first == pivot) ? nullptr : make_unique<WaveletNode> (first, pivot, lo, mid);
        right = (pivot == last) ? nullptr : make_unique<WaveletNode> (pivot, last, mid + 1, hi);
      } else {
        left = nullptr;
        right = nullptr;
      }
    }
    // return count of 0 in [0, i)
    size_t rank0(size_t i) const {
      return Bc[i];
    }
    size_t rank1(size_t i) const {
      return i - rank0(i);
    }

    // #num >=k in [0,i)
    size_t count_greater_or_equal(size_t i, T k) const {
      if(hi < k) {
        return 0;
      }
      if(lo >= k) {
        return i;
      }
      return (!left ? 0 : left->count_greater_or_equal(rank0(i), k)) +
              (!right ? 0 : right->count_greater_or_equal(rank1(i), k));
    }
    T index(size_t i) const {
      if(lo == hi) {
        return lo;
      }
      if(B[i] == 0) {
        return left->index(rank0(i));
      } else {
        return right->index(rank1(i));
      }
    }
    // return i-element in [L..R) 0-index  (sorted array)
    T quantile(size_t i, size_t L, size_t R) const {
      if(lo == hi) {
        return lo;
      }
      if(i < rank0(R) - rank0(L)) {
        return left->quantile(i, rank0(L), rank0(R));
      } else {
        return right->quantile(i - (rank0(R) - rank0(L)), rank1(L), rank1(R));
      }
    }

  };




  unique_ptr<WaveletNode> root;

  T lo, hi; // range of value
  template<typename Iterator>
  WaveletTree(Iterator first, Iterator last, T _lo, T _hi) : lo(_lo), hi(_hi) {
    vector<T> S(first, last);
//    root = new WaveletNode(S.begin(), S.end(), lo, hi);
    root = make_unique<WaveletNode> (S.begin(), S.end(), lo, hi);
  }
  template<typename Iterator>
  WaveletTree(Iterator first, Iterator last) :
    WaveletTree(first, last, *min_element(first, last), *max_element(first, last)) {}



  // #num >=k in [L,R)

  size_t count_greater_or_equal(T k, size_t L, size_t R) {
    return root->count_greater_or_equal(R, k) - root->count_greater_or_equal(L, k);
  }
  size_t count_greater(T k, size_t L, size_t R) {
    return count_greater_or_equal(k + 1, L, R);
  }
  size_t count_lesser_or_equal(T k, size_t L, size_t R) {
    return R - L - count_greater(k, L, R);
  }
  size_t count_lesser(T k, size_t L, size_t R) {
    return R - L - count_greater_or_equal(k, L, R);
  }
  size_t count_equal(T k, size_t L, size_t R) {
    return count_greater_or_equal(k, L, R) - count_greater(k, L, R);
  }

  size_t count_greater_or_equal(T k) {
    return count_greater_or_equal(k, 0, root->n);
  }
  size_t count_greater(T k) {
    return count_greater(k, 0, root->n);
  }
  size_t count_lesser_or_equal(T k) {
    return count_lesser_or_equal(k, 0, root->n);
  }
  size_t count_lesser(T k) {
    return count_lesser(k, 0, root->n);
  }
  size_t count_equal(T k) {
    return count_equal(k, 0, root->n);
  }

  T index(size_t i) const {
    return root->index(i);
  }

  T quantile(size_t i, size_t L, size_t R) const {
    return root->quantile(i, L, R);
  }

  T quantile(size_t i) const {
    return root->quantile(i, 0, root->n);
  }
};


int main(){
  // INIT
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> dis(0, numeric_limits<int>::max());

  ios::sync_with_stdio(0), cin.tie(0);
  int n = 100000, val = 100;
  vector<int> a;
  for(int i = 0; i < n; i++) {
    a.push_back(dis(rng) % val);
  }
  debug(a);

  WaveletTree<int> wt(a.begin(), a.end());

  vector<int> sorted_a(a.begin(), a.end());
  sort(sorted_a.begin(), sorted_a.end());
  // INIT
  puts("[Index]");
  // index
  for(int i = 0; i< a.size(); i++) {
    assert(wt.index(i) == a[i]);
  }
  // index
  puts("[Quantile]");
  // quantile
  for(int i = 0; i < 100; i++) {
    int l = dis(rng) % (n + 1);
    int r = dis(rng) % (n + 1);
    if(l > r) {
      swap(l, r);
    }
    if(l == r) {
      continue;
    }
    debug(l, r);
    vector<int> b(a.begin() + l, a.begin() + r);
    sort(b.begin(), b.end());
    for(int k = l; k < r; k++) {
      assert(wt.quantile(k - l, l, r) == b[k - l]);
    }
    int j = dis(rng) % (n + 1);
    assert(wt.quantile(j) == sorted_a[j]);
  }
  // quantile
  puts("[Count-K]");
  // count k
  for(int i = 0; i < 100; i++) {
    int l = dis(rng) % (n + 1);
    int r = dis(rng) % (n + 1);
    int k = dis(rng) % val;
    if(l > r) {
      swap(l, r);
    }
    //>, >=, =, <=, <
    vector<int> cnt(5);
    for(int j = l; j < r; j++) {
      if(a[j] > k) {
        cnt[0]++;
      }
      if(a[j] >= k) {
        cnt[1]++;
      }
      if(a[j] == k) {
        cnt[2]++;
      }
      if(a[j] <= k) {
        cnt[3]++;
      }
      if(a[j] < k) {
        cnt[4]++;
      }
    }
    debug(cnt);
    assert(cnt[0] == wt.count_greater(k, l, r));
    assert(cnt[1] == wt.count_greater_or_equal(k, l, r));
    assert(cnt[2] == wt.count_equal(k, l, r));
    assert(cnt[3] == wt.count_lesser_or_equal(k, l, r));
    assert(cnt[4] == wt.count_lesser(k, l, r));
  }

  for(int i = 0; i < 100; i++) {
    int k = dis(rng) % val;
    vector<int> cnt(5);
    for(int j = 0; j < n; j++) {
      if(a[j] > k) {
        cnt[0]++;
      }
      if(a[j] >= k) {
        cnt[1]++;
      }
      if(a[j] == k) {
        cnt[2]++;
      }
      if(a[j] <= k) {
        cnt[3]++;
      }
      if(a[j] < k) {
        cnt[4]++;
      }
    }
    assert(cnt[0] == wt.count_greater(k));
    assert(cnt[1] == wt.count_greater_or_equal(k));
    assert(cnt[2] == wt.count_equal(k));
    assert(cnt[3] == wt.count_lesser_or_equal(k));
    assert(cnt[4] == wt.count_lesser(k));
  }


  // count k
  puts("PASS ALL");
}
