#include<bits/stdc++.h>
using namespace std;

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    int n;
    vector<vector<T>> st;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        st.resize(max_log);
        st[0] = a;
        for (int j = 1; j < max_log; j++) {
            st[j].resize(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[j][i] = func(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int l, int r) const {
        assert(0 <= l && l <= r && r <= n - 1);
        int lg = 31 - __builtin_clz(r - l + 1);
        return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
    }
};

int main() {
    vector<int> a;
    a = {91, -5, 2, 0, 987, -3};
	SparseTable<int> st(a, [&](int i, int j){ return min(i, j); });
    for(int i = 0; i < a.size(); i++)
    for(int j = i; j < a.size(); j++){
        int mn = 1e9 + 7;
        for(int k = i; k <= j; k++){
            mn = min(mn, a[k]);
        }
        assert(mn == st.get(i, j));
    }
    SparseTable<int> st2(a, [&](int i, int j){ return max(i, j); });
    for(int i = 0; i < a.size(); i++)
    for(int j = i; j < a.size(); j++){
        int mx = -(1e9 + 7);
        for(int k = i; k <= j; k++){
            mx = max(mx, a[k]);
        }
        assert(mx == st2.get(i, j));
    }

    cout << "Success\n" ;
}
