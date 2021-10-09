struct Segtree {
    vector<ll> seg, lazy;
    int n, LOG;

    Segtree(int n=0){
        this->n = n;
        LOG = ceil(log2(n));
        seg.assign(2*n, 0);
        lazy.assign(2*n, 0);
    }

    ll merge(ll a, ll b){
        return a + b;
    }
    void poe(int p, ll x, int tam, bool prop=1){
        seg[p] += x*tam;
        if(prop and p < n) lazy[p] += x;
    }
    void sobe(int p){
        for(int tam = 2; p /= 2; tam *= 2){
            seg[p] = merge(seg[2*p], seg[2*p+1]);
            if(lazy[p]!=0)
                poe(p, lazy[p], tam, 0);
        }
    }
    void prop(int p){
        int tam = 1 << (LOG-1);
        for(int s = LOG; s; s--, tam /= 2){
            int i = p >> s;
            if(lazy[i]){
                poe(2*i, lazy[i], tam);
                poe(2*i+1, lazy[i], tam);
                lazy[i] = 0;
            }
        }
    }
    void build(){
        for(int i = n-1; i; i--)
            seg[i] = merge(seg[2*i], seg[2*i+1]);
    }
    ll query(int a, int b){
        ll ret = 0;
        for(prop(a+=n), prop(b+=n); a <= b; ++a/=2, --b/=2) {
            if(a%2 == 1) ret = merge(ret, seg[a]);
            if(b%2 == 0) ret = merge(ret, seg[b]);
        }
        return ret;
    }
    void update(int a, int b, int x){
        int a2 = a += n, b2 = b += n, tam = 1;
        for(; a <= b; ++a/=2, --b/=2, tam *= 2){
            if(a%2 == 1) poe(a, x, tam);
            if(b%2 == 0) poe(b, x, tam);
        }
        sobe(a2), sobe(b2);
    }
};