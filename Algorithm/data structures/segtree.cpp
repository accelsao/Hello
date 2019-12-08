struct segtree{
	public:
	struct node{
        Mint prod = 1;
        Mint sum = 0;
        void apply(int l, int r, Mint val){
            prod = val;
            sum = 1;
        }
	};
	node unite(const node& a, const node& b) const{
        node res;
        res.sum = a.sum + a.prod * b.sum;
        res.prod = a.prod * b.prod;
        return res;
	}

	inline void push(int x, int l, int r){
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
//        if(tree[x].add != 0){
//            tree[x + 1].apply(x + 1, y, tree[x].add);
//            tree[z].apply(y + 1, r, tree[x].add);
//            tree[x].add = 0;
//        }
	}
	inline void pull(int x, int z){
        tree[x] = unite(tree[x + 1], tree[z]);
	}
	int n;
	vector<node> tree;
    void build(int x, int l, int r){
        if(l == r){
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }
    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }
    node get(int x, int l, int r, int ll, int rr){
        if(ll <= l && rr >= r){
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res;
        if(y >= rr){
            res = get(x + 1, l, y, ll, rr);
        }
        else{
            if(y < ll){
                res = get(z, y + 1, r, ll, rr);
            }
            else{
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }

    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M&... v){
        if(ll <= l && r <= rr){
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if(y >= ll){
            modify(x + 1, l, y, ll, rr, v...);
        }
        if(y < rr){
            modify(z, y + 1, r, ll, rr, v...);
        }
        pull(x, z);
    }

    segtree(int _n) : n(_n){
        assert(n > 0);
        tree.resize(n + n - 1);
        build(0, 0, n-1);
    }

    template <typename M>
    segtree(const vector<M> &v){
        n = v.size();
        assert(n > 0);
        tree.resize(n + n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr){
        assert(0 <= ll && ll <= rr & rr <= n - 1);
        return get(0, 0, n-1, ll, rr);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }

};
