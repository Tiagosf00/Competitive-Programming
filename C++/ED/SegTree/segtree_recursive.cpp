int n;
vector<ll> t(4*N, 0);
vector<ll> v(N, 0);
vector<ll> lazy(4*N, 0);

inline ll merge(ll a, ll b){
    return a + b;
}

void build(int l=0, int r=n-1, int no=1){
    if(l == r){ t[no] = v[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*no);
    build(mid+1, r, 2*no+1);
    t[no] = merge(t[2*no], t[2*no+1]);
}

void prop(int l, int r, int no){
    if(lazy[no] != 0){
        t[no] += lazy[no] * (r-l+1);
        if(l != r){
            lazy[2*no] += lazy[no];
            lazy[2*no+1] += lazy[no];
        }
        lazy[no] = 0;
    }
}

ll query(int a, int b, int l=0, int r=n-1, int no=1){
    prop(l, r, no);
    if(r<a or b<l) return 0;
    if(a<=l and r<=b) return t[no];
    int mid = (l + r) / 2;
    return merge(
        query(a, b, l, mid, 2*no),
        query(a, b, mid+1, r, 2*no+1)
    );
}

void update(int a, int b, ll x, int l=0, int r=n-1, int no=1){
    prop(l, r, no);
    if(r<a or b<l) return;
    if(a<=l and r<=b){
        lazy[no] += x;
        prop(l, r, no);
        return;
    }
    int mid = (l + r) / 2;
    update(a, b, x, l, mid, 2*no);
    update(a, b, x, mid+1, r, 2*no+1);
    t[no] = merge(t[2*no], t[2*no+1]);
}