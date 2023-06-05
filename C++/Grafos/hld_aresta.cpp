// Use it together with recursive_segtree
const int N = 3e5+10;
vector<vector<pair<int, int>>> g(N, vector<pair<int,int>>());
vector<int> in(N), inv(N), sz(N);
vector<int> peso(N), pai(N);
vector<int> head(N), tail(N), h(N);

int tin;

void dfs(int u, int p=-1, int depth=0){
    sz[u] = 1; h[u] = depth;
    for(auto &i: g[u]) if(i.ff != p){
        auto [v, w] = i;
        dfs(v, u, depth+1);
        pai[v] = u; sz[u] += sz[v]; peso[v] = w;
        if (sz[v] > sz[g[u][0].ff] or g[u][0].ff == p) swap(i, g[u][0]);
    }
}
void build_hld(int u, int p = -1) {
    v[in[u] = tin++] = peso[u]; tail[u] = u;
    inv[tin-1] = u;
    for(auto &i: g[u]) if(i.ff != p) {
        int v = i.ff;
        head[v] = (i == g[u][0] ? head[u] : v);
        build_hld(v, u);
    }
    if(g[u].size() > 1) tail[u] = tail[g[u][0].ff];
}
void init_hld(int root = 0) {
    dfs(root);
    tin = 0;
    build_hld(root);
    build();
}
void reset(){
    g.assign(N, vector<pair<int,int>>());
    in.assign(N, 0), sz.assign(N, 0);
    peso.assign(N, 0), pai.assign(N, 0);
    head.assign(N, 0); tail.assign(N, 0);
    h.assign(N, 0); inv.assign(N, 0);

    t.assign(4*N, 0); v.assign(N, 0);
    lazy.assign(4*N, 0);
}
ll query_path(int a, int b) {
    if (a == b) return 0;
    if(in[a] < in[b]) swap(a, b);

    if(head[a] == head[b]) return query(in[b]+1, in[a]);
    return merge(query(in[head[a]], in[a]), query_path(pai[head[a]], b));
}
void update_path(int a, int b, int x) {
    if (a == b) return;
    if(in[a] < in[b]) swap(a, b);

    if(head[a] == head[b]) return (void)update(in[b]+1, in[a], x);
    update(in[head[a]], in[a], x); update_path(pai[head[a]], b, x);
}
ll query_subtree(int a) {
    if(sz[a] == 1) return 0;
    return query(in[a]+1, in[a]+sz[a]-1);
}
void update_subtree(int a, int x) {
    if(sz[a] == 1) return;
    update(in[a]+1, in[a]+sz[a]-1, x);
}
int lca(int a, int b) {
    if(in[a] < in[b]) swap(a, b);
    return head[a] == head[b] ? b : lca(pai[head[a]], b);
}
