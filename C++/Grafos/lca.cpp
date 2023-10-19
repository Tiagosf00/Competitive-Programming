const int LOG = 22;
vector<vector<int>> g(N);
int t, n;
vector<int> in(N), height(N);
vector<vector<int>> up(LOG, vector<int>(N));
void dfs(int u, int h=0, int p=-1) {
    up[0][u] = p;
    in[u] = t++;
    height[u] = h;
    for (auto v: g[u]) if (v != p) dfs(v, h+1, u);
}

void blift() {
    up[0][0] = 0;
    for (int j=1;j<LOG;j++) {
        for (int i=0;i<n;i++) {
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }
}
 
int lca(int u, int v) {
    if (u == v) return u;
    if (in[u] < in[v]) swap(u, v);
    for (int i=LOG-1;i>=0;i--) {
        int u2 = up[i][u];
        if (in[u2] > in[v])
            u = u2;
    }
    return up[0][u];
}

t = 0;
dfs(0);
blift();

// lca O(1)

template<typename T> struct rmq {
    vector<T> v;
    int n; static const int b = 30;
    vector<int> mask, t;

    int op(int x, int y) { return v[x] < v[y] ? x : y; }
    int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
    rmq() {}
    rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
        for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
            at = (at<<1)&((1<<b)-1);
            while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
        }
        for (int i = 0; i < n/b; i++) t[i] = b*i+b-1-msb(mask[b*i+b-1]);
        for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
            t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
    }
    int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
    T query(int l, int r) {
        if (r-l+1 <= b) return small(r, r-l+1);
        int ans = op(small(l+b-1), small(r));
        int x = l/b+1, y = r/b-1;
        if (x <= y) {
            int j = msb(y-x+1);
            ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
        }
        return ans;
    }
};

namespace lca {
    vector<int> g[N];
    int v[2*N], pos[N], dep[2*N];
    int t;
    rmq<int> RMQ;

    void dfs(int i, int d = 0, int p = -1) {
        v[t] = i, pos[i] = t, dep[t++] = d;
        for (int j : g[i]) if (j != p) {
            dfs(j, d+1, i);
            v[t] = i, dep[t++] = d;
        }
    }
    void build(int n, int root) {
        t = 0;
        dfs(root);
        RMQ = rmq<int>(vector<int>(dep, dep+2*n-1));
    }
    int lca(int a, int b) {
        a = pos[a], b = pos[b];
        return v[RMQ.query(min(a, b), max(a, b))];
    }
    int dist(int a, int b) {
        return dep[pos[a]] + dep[pos[b]] - 2*dep[pos[lca(a, b)]];
    }
}