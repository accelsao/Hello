template <typename T>
vector<int> kmp_table(int n, const T &s){
    vector<int> pi(n);
    int j = 0;
    for(int i = 1; i < n; i++){
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

template <typename T>
vector<int> kmp_table(const T &s){
    return kmp_table((int)s.size(), s);
}

template <typename T>
vector<int> kmp_search(int n, const T &s, int m, const T &t, const vector<int> &pi){
    assert(n > 0 && (int)pi.size() == n);
    vector<int> res;
    int j = 0;
    for(int i = 0; i < m; i++){
        while(j > 0 && (j == n || (t[i] != s[j]))){
            j = pi[j - 1];
        }
        if(t[i] == s[j]){
            j++;
        }
        if(j == n){
            res.push_back(i - n + 1);
        }
    }
    return res;
    // return 0-indexed positions of occurrences of w in s
}

template <typename T>
vector<int> kmp_search(const T &s, const T &w, const vector<int> &pi){
    return kmp_search((int) s.size(), s, (int) w.size(), w, pi);
}

/*
string s = "aab";
string t = "aabdbaabeeabaabz";
vector<int> res = kmp_search(s, t, kmp_table(s));
for(int p: res){
    cout << t.substr(p, (int)s.size()) << endl;
}
output:
aab
aab
aab
*/
