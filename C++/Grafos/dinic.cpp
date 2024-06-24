// Description: Flow algorithm with complexity O(VE log U) where U = max |cap|.
// O(min(E^{1/2}, V^{2/3})E) if U = 1; O(sqrt(V)E)$ for bipartite matching.
// testado em https://www.spoj.com/problems/FASTFLOW/ 0.20s
const int N = 200003;
template<typename T> struct Dinic {
    struct Edge {
        int from, to;
        T c, f;
        Edge(int from, int to, T c, T f): from(from), to(to), c(c), f(f) {}
    };

    vector<Edge> edges;
    int tempo = 0, id = 0;
    int lvl[N], vis[N], qu[N], nxt[N];
    vector<int> adj[N];
    T INF = (ll)1e14;
    #warning botar INF certo no dinic

    void addEdge(int a, int b, T c, T rc=0) {
        edges.pb({a, b, c, 0});
        adj[a].pb(id++);
        edges.pb({b, a, rc, 0});
        adj[b].pb(id++);
    }

    bool bfs(int s, int t) {
        tempo++;
        vis[s] = tempo;
        int qt = 0;
        qu[qt++] = s;
        lvl[s] = 0;

        for(int i = 0; i < qt; i++) {
            int u = qu[i];
            nxt[u] = 0;

            for(auto idx : adj[u]) {
                auto& e = edges[idx];
                if(e.f >= e.c or vis[e.to] == tempo) continue;
                // from[e.to] = idx; pra usar a outra dfs
                vis[e.to] = tempo;
                lvl[e.to] = lvl[u]+1;
                qu[qt++] = e.to;
            }
        }
        return (vis[t] == tempo);
    }

    T dfs(int s, int t, T f) {
        if(s == t) return f;

        T res = 0;
        for(; nxt[s] < (int)adj[s].size(); nxt[s]++) {
            int idx = adj[s][nxt[s]];
            auto& e = edges[idx];
            auto& rev = edges[idx^1];

            if(e.f >= e.c or lvl[e.to] != lvl[s]+1) continue;
            T flow = dfs(e.to, t, min(f, e.c-e.f));
            res += flow;
            e.f += flow;
            rev.f -= flow;
            f -= flow;

            if(!f) break;
        }
        return res;
    }

//    dfs boa para grafos pequenos (n <= 500?), ruim para fluxos grandes?
//    tem que criar o vetor from pra usar e marcar o from na bfs
//    T dfs(int s, int t) {
//         T res = INF;

//         for(int u = t; u != s; u = edges[from[u]].from) {
//             res = min(res, edges[from[u]].c-edges[from[u]].f);
//         }

//         for(int u = t; u != s; u = edges[from[u]].from) {
//             edges[from[u]].f += res;
//             edges[from[u]^1].f -= res;
//         }

//         return res;
//     }

    T flow(int s, int t) {
        T flow = 0;
        while(bfs(s, t)) {
            flow += dfs(s, t, INF);
        }
        return flow;
    }

    // NAO TESTADO DAQUI PRA BAIXO, MAS DEVE FUNCIONAR
    void reset_flow() {
        for(int i = 0; i < id; i++) // aqui eh id mesmo ne?
            edges[i].flow = 0;
        memset(lvl, 0, sizeof(lvl));
        memset(vis, 0, sizeof(vis));
        memset(qu, 0, sizeof(qu));
        memset(nxt, 0, sizeof(nxt));
        tempo = 0;
    }
    vector<pair<int, int>> cut() {
        vector<pair<int, int>> cuts;
        for (auto [from, to, flow, cap]: edges) {
            if (flow == cap and vis[from] == tempo and vis[to] < tempo and cap>0) {
                cuts.pb({from, to});
            }
        }
        return cuts;
    }
};
