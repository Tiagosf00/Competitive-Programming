vector<ll> t(4*N, 0);
vector<ll> lazy(4*N, 0);

inline ll f(ll a, ll b) {
    return a + b;
}

void build(vector<int> &v, int lx=0, int rx=N-1, int x=1) {
    if (lx == rx) { if (lx < v.size()) t[x] = v[lx]; return; }
    int mid = (lx + rx) / 2;
    build(v, lx, mid, 2*x);
    build(v, mid+1, rx, 2*x+1);
    t[x] = f(t[2*x], t[2*x+1]);
}

void prop(int lx, int rx, int x) {
    if (lazy[x] != 0) {
        t[x] += lazy[x] * (rx-lx+1);
        if (lx != rx) {
            lazy[2*x] += lazy[x];
            lazy[2*x+1] += lazy[x];
        }
        lazy[x] = 0;
    }
}

ll query(int l, int r, int lx=0, int rx=N-1, int x=1) {
    prop(lx, rx, x);
    if (r < lx or rx < l) return 0;
    if (l <= lx and rx <= r) return t[x];
    int mid = (lx + rx) / 2;
    return f(
        query(l, r, lx, mid, 2*x),
        query(l, r, mid+1, rx, 2*x+1)
    );
}

void update(int l, int r, ll val, int lx=0, int rx=N-1, int x=1) {
    prop(lx, rx, x);
    if (r < lx or rx < l) return;
    if (l <= lx and rx <= r) {
        lazy[x] += val;
        prop(lx, rx, x);
        return;
    }
    int mid = (lx + rx) / 2;
    update(l, r, val, lx, mid, 2*x);
    update(l, r, val, mid+1, rx, 2*x+1);
    t[x] = f(t[2*x], t[2*x+1]);
}