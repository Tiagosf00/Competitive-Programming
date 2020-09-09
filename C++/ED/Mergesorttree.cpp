struct ST { // indexado em 0, O(n * log^2(n) )
    int size;
    vector<vl> v;

    vl f(vl a, vl& b) {
        vl res = a;
        for(auto val : b) {
            res.pb(val);
        }
        sort(all(res));
        return res;
    }

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        v.assign(2*size, vl());
    }

    void build(vector<ll>& a, int x, int lx, int rx) {
        if(rx-lx == 1) {
            if(lx < (int)a.size()) {
                v[x].pb(a[lx]);
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x +1, lx, m);
        build(a, 2*x +2, m, rx);
        v[x] = f(v[2*x +1], v[2*x + 2]);
    }

    void build(vector<ll>& a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    ll greaterequal(int l, int r, int k, int x, int lx, int rx) {
        if(r <= lx or l >= rx) return 0;
        if(l <= lx && rx <= r) {
            auto it = lower_bound(all(v[x]), k);
            return (v[x].end() - it);
        }
        int m = (lx + rx)/2;
        ll s1 = greaterequal(l, r, k, 2*x +1, lx, m);
        ll s2 = greaterequal(l, r, k, 2*x +2, m, rx);

        return s1 +s2;
    }

    ll greaterequal(int l, int r, int k) {
        return greaterequal(l, r+1, k, 0, 0, size);
    }
};
