// LIS 3D problem

struct Segtree{
    vi t;
    int n;

    Segtree(int n){
        this->n = n;
        t.assign(2*n, 0);
    }

    int merge(int a, int b){
        return max(a, b);
    }

    void build(){
        for(int i=n-1;i>0;i--)
            t[i] = merge(t[i<<1], t[i<<1|1]);
    }

    int query(int l, int r){
        int resl = -INF, resr = -INF;
        for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
            if(l&1) resl = merge(resl, t[l++]);
            if(r&1) resr = merge(t[--r], resr);
        }
        return merge(resl, resr);
    }

    void update(int p, int value){
        p+=n;
        for(t[p]=max(t[p], value); p >>= 1;)
            t[p] = merge(t[p<<1], t[p<<1|1]);
    }
};

struct point{
    int x, y, z, id;
    bool left;
    point(int x=0, int y=0, int z=0): x(x), y(y), z(z){
        left = false;
    }
    bool operator<(point &o){
        if(x != o.x) return x < o.x;
        if(y != o.y) return y > o.y;
        return z < o.z;
    }
};


void cdq(int l, int r, vector<point> &a, vi &dp){
    if(l==r) return;

    int mid = (l+r) / 2;

    cdq(l, mid, a, dp);

    // compress z
    set<int> uz; map<int, int> idz;
    for(int i=l;i<=r;i++) uz.insert(a[i].z);
    int id = 0;
    for(auto z: uz) idz[z] = id++;

    vector<point> tmp;
    for(int i=l;i<=r;i++){
        tmp.pb(a[i]);
        tmp.back().x = 0;
        tmp.back().z = idz[tmp.back().z];
        if(i<=mid)
            tmp.back().left = true;
    }

    Segtree st(id);

    sort(tmp.rbegin(), tmp.rend());

    for(auto t: tmp){
        if(t.left){
            st.update(t.z, dp[t.id]);
        }else{
            dp[t.id] = max(dp[t.id], st.query(0, t.z-1)+1);
        }
    }

    cdq(mid+1, r, a, dp);
}


int32_t main()
{sws;

    int n; cin >> n;

    vector<point> vet(n);
    for(int i=0;i<n;i++){
        cin >> vet[i].x >> vet[i].y >> vet[i].z;
    }

    sort(vet.begin(), vet.end());

    for(int i=0;i<n;i++)
        vet[i].id = i;

    vi dp(n, 1);

    cdq(0, n-1, vet, dp);

    int ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans, dp[i]);

    cout << ans << endl;


    return 0;
}