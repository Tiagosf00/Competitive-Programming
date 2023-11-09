vector<int> g[N];
int sz[N], rem[N];

void dfs(vector<int>& path, int u, int d=0, int p=-1) {
    path.push_back(d);
    for (int v : g[u]) if (v != p and !rem[v]) dfs(path, v, d+1, u);
}

int dfs_sz(int u, int p=-1) {
    sz[u] = 1;
    for (int v : g[u]) if (v != p and !rem[v]) sz[u] += dfs_sz(v, u);
    return sz[u];
}

int centroid(int u, int p, int size) {
    for (int v : g[u]) if (v != p and !rem[v] and 2 * sz[v] > size)
        return centroid(v, u, size);
    return u;
}

ll decomp(int u, int k) {
    int c = centroid(u, u, dfs_sz(u));
    rem[c] = true;

    ll ans = 0;
    vector<int> cnt(sz[u]);
    cnt[0] = 1;
    for (int v : g[c]) if (!rem[v]) {
        vector<int> path;
        dfs(path, v);
        // d1 + d2 + 1 == k
        for (int d : path) if (0 <= k-d-1 and k-d-1 < sz[u])
            ans += cnt[k-d-1];
        for (int d : path) cnt[d+1]++;
    }

    for (int v : g[c]) if (!rem[v]) ans += decomp(v, k);
    return ans;
}
