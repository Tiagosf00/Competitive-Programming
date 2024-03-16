struct virtual_tree {
    int n;
    vector<vector<int>> g, vt;
    vector<int> in, out, t;
    int T, E;

    virtual_tree(int n): n(n) {
        g.resize(n);
        T = 0; E = 2*n;
        vt.resize(n); in.resize(n); out.resize(n);
        t.resize(4*n);
    }
    void build() {
        dfs_time(1);
        build_st();
    }
    void dfs_time(int u, int p = 0) {
        in[u] = ++T;
        t[T + E] = u;
        for (int v: g[u]) if (v != p) {
            dfs_time(v, u);
            t[++T + E] = u;
        }
        out[u] = T;
    }

    int take(int u, int v) { return in[u] < in[v] ? u : v; }
    void build_st() {
        in[0] = 0x3f3f3f3f;
        for (int i=E-1; i>0; i--)
            t[i] = take(t[i<<1], t[i<<1|1]);
    }
    int query(int l, int r) {
        int ans = 0;
        for (l+=E, r+=E; l<r; l>>=1, r>>=1) {
            if (l&1) ans = take(ans, t[l++]);
            if (r&1) ans = take(ans, t[--r]);
        }
        return ans;
    }
    int lca(int u, int v) {
        if (in[u] > in[v]) swap(u, v);
        return query(in[u], out[v]+1);
    }

    int build_vt(vector<int> &nodes) {
        auto cmp = [&](int u, int v) { return in[u] < in[v]; };
        auto covers = [&](int u, int v) { return in[u] <= in[v] and out[u] >= out[v]; };
        sort(nodes.begin(), nodes.end(), cmp);
        int n = nodes.size();
        for (int i = 0; i < n-1; i++) {
            int u = nodes[i], v = nodes[i+1];
            nodes.push_back(lca(u, v));
        }
        sort(nodes.begin(), nodes.end(), cmp);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

        for (int u: nodes) vt[u].clear();

        stack<int> s;
        for (int u: nodes) {
            while (!s.empty() and !covers(s.top(), u))
                s.pop();
            if (!s.empty()) vt[s.top()].push_back(u);
            s.push(u);
        }
        return nodes[0]; // root
    }
};
