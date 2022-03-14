vector<int> g[MAX], gt[MAX], S; int vis[MAX], cor[MAX];

int val(int n, bool tvalue) {
    if(tvalue) return 2*n;
    return 2*n +1;
}

void dfs(int u) {
    vis[u] = 1; for(int v : g[u]) if(!vis[v]) dfs(v);
    S.push_back(u);
}

void dfst(int u, int e) {
    cor[u] = e;
    for(int v : gt[u]) if(!cor[v]) dfst(v, e);
}

void kosaraju(int n) {
    for(int i = 0; i <= n; i++) if(!vis[i]) dfs(i);
    for(int i = 0; i <= n; i++) for(int j : g[i])
        gt[j].push_back(i);
    int e = 0; reverse(S.begin(), S.end());
    for(int u : S) if(!cor[u]) dfst(u, ++e);
}

// antes de chamar essa funcao, colocar as arestas do grafo
bool solve(int n, vi &res) {
    kosaraju(2*n); // MAX > 2*N
    vi r;

    forn(i, n) {
        int t = val(i, true), f = val(i, false);
        if(cor[t] == cor[f]) {
            return false;
        }
        else {
            if(cor[t] > cor[f])
                r.pb(1);
            else
                r.pb(0);
        }
    }
    swap(r, res);
    return true;
}
