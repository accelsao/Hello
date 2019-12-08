class dsu {
public:
    vector<int> p;
    vector<int> rk;
    int n;
    dsu(int _n) : n(_n){
        p.resize(n);
        rk.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(rk.begin(), rk.end(), 1);
    }
    inline int get(int x){
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    inline bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x != y){
            if(rk[x] >= rk[y]){
                p[y] = x;
                rk[x] += rk[y];
                rk[y] = 0;
            }
            else{
                p[x] = y;
                rk[y] += rk[x];
                rk[x] = 0;
            }

            return true;
        }
        return false;
    }
};
