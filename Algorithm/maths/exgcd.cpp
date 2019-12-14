template<class T>
tuple<T, T, T> exGcd(T a, T b) {
    //ax+by=gcd(a,b)
    if(b == 0){
        return make_tuple(a, 1, 0);
    }
    T gcd, x, y, k = a / b;
    tie(gcd, x, y) = exGcd(b, a - k * b);
    return make_tuple(gcd, y, x - k * y);
}

long long CRT(vector<long long> mod, vector<long long> a){
    // link: https://codeforces.com/blog/entry/61290
    long long lcm = mod[0];
    long long ans = a[0];
    int n = a.size();
    assert(n == mod.size());
    for(int i = 1; i < n; i++){
        long long gcd, x, y;
        tie(gcd, x, y) = exGcd(lcm, mod[i]);
        if((a[i] - ans) % gcd != 0){
            return -1;
        }
        long long k = (x * (a[i] - ans) / gcd) % (mod[i] / gcd) * lcm;
        lcm = mod[i] / gcd * lcm;
        ans = ((ans + k) % lcm + lcm) % lcm;
    }
    return ans;
}
