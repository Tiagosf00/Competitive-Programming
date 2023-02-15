vector<int> g[N];
int sz[N], rem[N];

void dfs(vector<int>& path, int i, int l=-1, int d=0) {
    path.push_back(d);
    for (int j : g[i]) if (j != l and !rem[j]) dfs(path, j, i, d+1);
}

int dfs_sz(int i, int l=-1) {
    sz[i] = 1;
    for (int j : g[i]) if (j != l and !rem[j]) sz[i] += dfs_sz(j, i);
    return sz[i];
}

int centroid(int i, int l, int size) {
    for (int j : g[i]) if (j != l and !rem[j] and sz[j] > size / 2)
        return centroid(j, i, size);
    return i;
}

ll decomp(int i, int k) {
    int c = centroid(i, i, dfs_sz(i));
    rem[c] = true;

    ll ans = 0;
    vector<int> cnt(sz[i]);
    cnt[0] = 1;
    for (int j : g[c]) if (!rem[j]) {
        vector<int> path;
        dfs(path, j);
        // d1 + d2 + 1 == k
        for (int d : path) if (0 <= k-d-1 and k-d-1 < sz[i])
            ans += cnt[k-d-1];
        for (int d : path) cnt[d+1]++;
    }

    for (int j : g[c]) if (!rem[j]) ans += decomp(j, k);
    return ans;
}