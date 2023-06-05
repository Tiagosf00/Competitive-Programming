// Use it together with recursive_segtree
const int N = 3e5+10;
vector<vector<int>> g(N, vector<int>());
vector<int> in(N), inv(N), sz(N);
vector<int> peso(N), pai(N);
vector<int> head(N), tail(N), h(N);

int tin;

void dfs(int u, int p=-1, int depth=0){
    sz[u] = 1; h[u] = depth;
    for(auto &v: g[u]) if(v != p){
        dfs(v, u, depth+1);
        pai[v] = u; sz[u] += sz[v];
        if (sz[v] > sz[g[u][0]] or g[u][0] == p) swap(v, g[u][0]);
    }
}
void build_hld(int u, int p = -1) {
    v[in[u] = tin++] = peso[u]; tail[u] = u;
    inv[tin-1] = u;
    for(auto &v: g[u]) if(v != p) {
        head[v] = (v == g[u][0] ? head[u] : v);
        build_hld(v, u);
    }
    if(g[u].size() > 1) tail[u] = tail[g[u][0]];
}
void init_hld(int root = 0) {
    dfs(root);
    tin = 0;
    build_hld(root);
    build();
}
void reset(){
    g.assign(N, vector<int>());
    in.assign(N, 0), sz.assign(N, 0);
    peso.assign(N, 0), pai.assign(N, 0);
    head.assign(N, 0); tail.assign(N, 0);
    h.assign(N, 0); inv.assign(N, 0);

    t.assign(4*N, 0); v.assign(N, 0);
    lazy.assign(4*N, 0);
}
ll query_path(int a, int b) {
    if(in[a] < in[b]) swap(a, b);

    if(head[a] == head[b]) return query(in[b], in[a]);
    return merge(query(in[head[a]], in[a]), query_path(pai[head[a]], b));
}
void update_path(int a, int b, int x) {
    if(in[a] < in[b]) swap(a, b);

    if(head[a] == head[b]) return (void)update(in[b], in[a], x);
    update(in[head[a]], in[a], x); update_path(pai[head[a]], b, x);
}
ll query_subtree(int a) {
    return query(in[a], in[a]+sz[a]-1);
}
void update_subtree(int a, int x) {
    update(in[a], in[a]+sz[a]-1, x);
}
int lca(int a, int b) {
    if(in[a] < in[b]) swap(a, b);
    return head[a] == head[b] ? b : lca(pai[head[a]], b);
}
