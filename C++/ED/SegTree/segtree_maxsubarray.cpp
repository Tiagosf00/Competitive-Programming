// Subarray with maximum sum
struct no{
    ll p, s, t, b; // prefix, suffix, total, best
    no(ll x=0): p(x), s(x), t(x), b(x){}
};

struct Segtree{
    vector<no> t;
    int n;

    Segtree(int n){
        this->n = n;
        t.assign(2*n, no(0));
    }

    no merge(no l, no r){
        no ans;
        ans.p = max(0LL, max(l.p, l.t+r.p));
        ans.s = max(0LL, max(r.s, l.s+r.t));
        ans.t = l.t+r.t;
        ans.b = max(max(l.b, r.b), l.s+r.p);
        return ans;
    }

    void build(){
        for(int i=n-1; i>0; i--)
            t[i]=merge(t[i<<1], t[i<<1|1]);
    }

    no query(int l, int r){ // idx 0
        no a(0), b(0);
        for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
            if(l&1)
                a=merge(a, t[l++]);
            if(r&1)
                b=merge(t[--r], b);
        }
        return merge(a, b);
    }

    void update(int p, int value){
        for(t[p+=n] = no(value); p >>= 1;)
            t[p] = merge(t[p<<1], t[p<<1|1]);
    }

};