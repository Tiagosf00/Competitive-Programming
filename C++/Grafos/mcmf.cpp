// Time: O(F E log(V)) where F is max flow. (reference needed)
const int N = 502;
template<typename T> struct MCMF {
    struct Edge {
        int from, to;
        T c, f, cost;
        Edge(int from, int to, T c, T cost): from(from), to(to), c(c), cost(cost) {}
    };

    vector<Edge> edges;
    int tempo = 0, id = 0;
    int nxt[N], vis[N];
    vector<int> adj[N];
    T lvl[N];
    const T INF = 1e15;

    void addEdge(int a, int b, int c, int cost) {
        edges.pb({a, b, c, cost});
        adj[a].pb(id++);
        edges.pb({b, a, 0, -cost});
        adj[b].pb(id++);
    }

    pair<T,T> dfs(int s, int t, T f) {
        if(s == t or f == 0) return {f, 0};

        pair<T, T> res = {0, 0};
        for(; nxt[s] < (int)adj[s].size(); nxt[s]++) {
            int idx = adj[s][nxt[s]];
            auto& e = edges[idx];
            auto& rev = edges[idx^1];

            if(e.f >= e.c or lvl[e.to] != lvl[s]+e.cost) continue;
            auto [flow, cost] = dfs(e.to, t, min(f, e.c-e.f));

            if(!flow) continue;

            res.ff += flow;
            res.ss += cost + flow*e.cost;
            e.f += flow;
            rev.f -= flow;
            f -= flow;

            if(!f) break;
        }
        return res;
    }

    // funciona v
    // pair<T,T> dfs(int s, int t) {
    //     pair<T,T> res = {INF, 0};

    //     for(int u = t; u != s; u = edges[from[u]].from) {
    //         res.ff = min(res.ff, edges[from[u]].c);
    //     }

    //     for(int u = t; u != s; u = edges[from[u]].from) {
    //         edges[from[u]].c -= res.ff;
    //         edges[from[u]^1].c += res.ff;
    //         res.ss += edges[from[u]].cost * res.ff;
    //     }

    //     return res;
    // }

    bool spfa(int s, int t) {
        for(int i = 0; i < N; i++) {
            lvl[i] = INF;
            vis[i] = 0;
        }
        lvl[s] = 0;
        vis[s] = 1;
        queue<int> q; q.push(s);

        while(q.size()) {
            int u = q.front(); q.pop();
            vis[u] = 0;
            nxt[u] = 0;

            for(auto idx : adj[u]) {
                auto& e = edges[idx];

                if(e.f >= e.c) continue;
                if(lvl[e.to] > lvl[u]+e.cost) {
                    lvl[e.to] = lvl[u]+e.cost;
                    if(!vis[e.to]) {
                        q.push(e.to);
                        vis[e.to] = 1;
                    }
                }

            }
        }
        return (lvl[t] < INF);
    }

    pair<T,T> flow(int s, int t) {
        pair<T,T> res = {0, 0};
        while(spfa(s, t)) {
            auto [flow, cost] = dfs(s, t, INF);
            res.ff += flow;
            res.ss += cost;
        }
        return res;
    }
};
