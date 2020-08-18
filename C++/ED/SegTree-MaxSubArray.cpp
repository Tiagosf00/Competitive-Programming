// Subarray with maximum sum
struct no{
    ll pref, suff, total, best;
    no(ll x=0): pref(x), suff(x), total(x), best(x){}
};

no merge(no l, no r){

    no ans;
    ans.pref = max(0LL, max(l.pref, l.total+r.pref));
    ans.suff = max(0LL, max(r.suff, l.suff+r.total));
    ans.total = l.total+r.total;
    ans.best = max(max(l.best, r.best), l.suff+r.pref);
    return ans;
}

struct Segtree{
    vector<no> t;
    int n;

    Segtree(int n){
        this->n = n;
        t.assign(2*n, no(0));
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