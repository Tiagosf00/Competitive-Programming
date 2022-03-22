bool initialized = false;
int original_root = 1;
const int E = 2 * N;
vector<int> vt[N]; // virtual tree edges
int in[N], out[N], T, t[E<<1];
void dfs_time(int u, int p = 0) {
    in[u] = ++T;
    t[T + E] = u;
    for (int v : g[u]) if (v != p) {
        dfs_time(v, u);
        t[++T + E] = u;
    }
    out[u] = T;
}

int take(int u, int v) { return in[u] < in[v] ? u : v; }
bool cmp_in(int u, int v) { return in[u] < in[v]; }
void build_st() {
    in[0] = 0x3f3f3f3f;
    for (int i = E-1; i > 0; i--)
        t[i] = take(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {
    int ans = 0;
    for (l+=E, r+=E; l < r; l>>=1, r>>=1) {
        if (l&1) ans = take(ans, t[l++]);
        if (r&1) ans = take(ans, t[--r]);
    }
    return ans;
}

int get_lca(int u, int v) {
    if (in[u] > in[v]) swap(u, v);
    return query(in[u], out[v]+1);
}

int covers(int u, int v) { // does u cover v?
    return in[u] <= in[v] && out[u] >= out[v];
}

int build_vt(vector<int>& vnodes) {
    assert(initialized);

    sort(all(vnodes), cmp_in);
    int n = vnodes.size();
    for (int i = 0; i < n-1; i++) {
        int u = vnodes[i], v = vnodes[i+1];
        vnodes.push_back(get_lca(u, v));
    }
    sort(all(vnodes), cmp_in);
    vnodes.erase(unique(all(vnodes)), vnodes.end());

    for (int u : vnodes)
        vt[u].clear();

    stack<int> s;
    for (int u : vnodes) {
        while (!s.empty() && !covers(s.top(), u))
            s.pop();
        if (!s.empty()) vt[s.top()].push_back(u);
        s.push(u);
    }
    return vnodes[0]; // root
}

void initialize() {
    initialized = true;
    dfs_time(original_root);
    build_st();
}
