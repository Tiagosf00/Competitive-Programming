struct Segtree{
    int n; vector<int> t;
    Segtree(int n): n(n), t(2*n, 0) {}

    int f(int a, int b) { return max(a, b); }

    void build(){
        for(int i=n-1; i>0; i--)
            t[i] = f(t[i<<1], t[i<<1|1]);
    }

    int query(int l, int r) { // [l, r]
        int resl = -INF, resr = -INF;
        for(l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
            if(l&1) resl = f(resl, t[l++]);
            if(r&1) resr = f(t[--r], resr);
        }
        return f(resl, resr);
    }

    void update(int p, int value) {
        for(t[p+=n]=value; p >>= 1;)
            t[p] = f(t[p<<1], t[p<<1|1]);
    }
};
