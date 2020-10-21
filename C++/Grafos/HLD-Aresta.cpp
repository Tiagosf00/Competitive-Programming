struct Hld {
    Segtree st;
    int n;
    vector<vii> g;
    vi pos, sz, sobe, pai, h, v;
    int t;

    Hld(int n){
        this->n=n;
        st = Segtree(n);
        g.assign(n, vii());
        pos.assign(n, 0);sz.assign(n, 0);
        sobe.assign(n, 0);pai.assign(n, 0);
        h.assign(n, 0);v.assign(n, 0);
    }

    void build_hld(int k, int p = -1, int f = 1){
        v[pos[k] = t++] = sobe[k]; sz[k] = 1;
        for(auto &i: g[k]) if(i.ff != p){
            sobe[i.ff] = i.ss; pai[i.ff] = k;
            h[i.ff] = (i==g[k][0] ? h[k]:i.ff);
            build_hld(i.ff, k, f); sz[k]+=sz[i.ff];

            if(sz[i.ff]>sz[g[k][0].ff] or g[k][0].ff==p) swap(i, g[k][0]);
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
        if(a==b) return 0;
        if(pos[a]<pos[b]) swap(a, b);

        if(h[a]==h[b]) return st.query(pos[b]+1, pos[a]);
        return st.query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
    }
    void update_path(int a, int b, int x){
        if(a==b) return;
        if(pos[a]<pos[b]) swap(a, b);

        if(h[a]==h[b]) return (void)st.update(pos[b]+1, pos[a], x);
        st.update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
    }
    ll query_subtree(int a){
        if(sz[a]==1) return 0;
        return st.query(pos[a]+1, pos[a]+sz[a]-1);
    }
    void update_subtree(int a, int x){
        if(sz[a]==1) return;
        st.update(pos[a]+1, pos[a]+sz[a]-1, x);
    }
    int lca(int a, int b){
        if(pos[a] < pos[b]) swap(a, b);
        return (h[a]==h[b] ? b:lca(pai[h[a]], b));
    }
};