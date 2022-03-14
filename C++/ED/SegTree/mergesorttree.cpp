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

    ST(int n) {
        size = n;
        v.assign(4*size, vl());
    }

    void build(vector<ll>& a, int lx=0, int rx=size-1, int x=1) {
        if(lx==rx) {
            v[x].pb(a[lx]);
            return;
        }
        int m = (lx+rx)/2;
        build(a, lx, m, 2*x);
        build(a, m+1, rx, 2*x+1);
        v[x] = f(v[2*x], v[2*x+1]);
    }

    ll greaterequal(int l, int r, int k, int lx=0, int rx=size-1, int x=1) {
        if(r < lx or l > rx) return 0;
        if(l <= lx and rx <= r) {
            auto it = lower_bound(all(v[x]), k);
            return (v[x].end() - it);
        }
        int m = (lx + rx)/2;
        ll s1 = greaterequal(l, r, k, lx, m, 2*x);
        ll s2 = greaterequal(l, r, k, m+1, rx, 2*x+1);

        return s1 + s2;
    }

};
