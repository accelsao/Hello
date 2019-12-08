template <typename T>
vector<int> z_function(int n, const T &s) {
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if(i <= r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
          z[i]++;
        }
        if (i + z[i] - 1 > r) {
          l = i;
          r = i + z[i] - 1;
        }
    }
    return z;
}

template <typename T>
vector<int> z_function(const T &s) {
  return z_function((int)s.size(), s);
}

/*
str[0:z[i]]=str[i:i+z[i]]
*/
