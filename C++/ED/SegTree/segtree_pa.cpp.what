int N;
vl t(4*MAX, 0);
vl v(MAX, 0);
vector<pll> lazy(4*MAX, {0,0});
// [x, x+y, x+2y...] //

inline ll merge(ll a, ll b){
    return a + b;
}

void build(int l=0, int r=N-1, int no=1){
    if(l == r){ t[no] = v[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2*no);
    build(mid+1, r, 2*no+1);
    t[no] = merge(t[2*no], t[2*no+1]);
}

inline pll sum(pll a, pll b){ return {a.ff+b.ff, a.ss+b.ss}; }

inline void prop(int l, int r, int no){
    auto [x, y] = lazy[no];
    if(x==0 and y==0) return;
    ll len = (r-l+1);
    t[no] += (x + x + y*(len-1))*len / 2;
    if(l != r){
        int mid = (l + r) / 2;
        lazy[2*no] = sum(lazy[2*no], lazy[no]);
        lazy[2*no+1] = sum(lazy[2*no+1], {x + (mid-l+1)*y, y});
    }
    lazy[no] = {0,0};
}

ll query(int a, int b, int l=0, int r=N-1, int no=1){
    prop(l, r, no);
    if(r<a or b<l) return 0;
    if(a<=l and r<=b) return t[no];
    int mid = (l + r) / 2;
    return merge(
        query(a, b, l, mid, 2*no),
        query(a, b, mid+1, r, 2*no+1)
    );
}

void update(int a, int b, ll x, ll y, int l=0, int r=N-1, int no=1){
    prop(l, r, no);
    if(r<a or b<l) return;
    if(a<=l and r<=b){
        lazy[no] = {x, y};
        prop(l, r, no);
        return;
    }
    int mid = (l + r) / 2;
    update(a, b, x, y, l, mid, 2*no);
    update(a, b, x + max((mid-max(l, a)+1)*y, 0LL), y, mid+1, r, 2*no+1);
    t[no] = merge(t[2*no], t[2*no+1]);
}
