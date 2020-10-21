struct Hld {
    Segtree st;
    int n;
    vector<vi> g;
    vi pos, sz, peso, pai, h, v;
    int t;

    Hld(int n){
        this->n=n;
        st = Segtree(n);
        g.assign(n, vi());
        pos.assign(n, 0);sz.assign(n, 0);
        peso.assign(n, 0);pai.assign(n, 0);
        h.assign(n, 0);v.assign(n, 0);
    }
 
    void build_hld(int k, int p = -1, int f = 1){
        v[pos[k] = t++] = peso[k]; sz[k] = 1;
        for(auto &i: g[k]) if(i!=p){
            pai[i] = k;
            h[i] = (i==g[k][0] ? h[k]:i);
            build_hld(i, k, f); sz[k]+=sz[i];
 
            if(sz[i]>sz[g[k][0]] or g[k][0]==p) swap(i, g[k][0]);
        }
        if(p*f == -1) build_hld(h[k] = k, -1, t = 0);
    }
    void build(int root = 0){
        t = 0;
        build_hld(root);
        for(int i=0;i<n;i++) st.seg[i+n]=v[i];
        st.build();
    }
    ll query_path(int a, int b){
        if(pos[a]<pos[b]) swap(a, b);
 
        if(h[a]==h[b]) return st.query(pos[b], pos[a]);
        return st.query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
    }
    void update_path(int a, int b, int x){
        if(pos[a]<pos[b]) swap(a, b);
 
        if(h[a]==h[b]) return (void)st.update(pos[b], pos[a], x);
        st.update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
    }
    ll query_subtree(int a){
        return st.query(pos[a], pos[a]+sz[a]-1);
    }
    void update_subtree(int a, int x){
        st.update(pos[a], pos[a]+sz[a]-1, x);
    }
    int lca(int a, int b){
        if(pos[a]<pos[b]) swap(a, b);
        return (h[a]==h[b] ? b:lca(pai[h[a]], b));
    }
};