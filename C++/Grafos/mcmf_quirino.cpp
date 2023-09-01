struct Dinitz {
  struct Edge {
    int v, u, cap, flow=0, cost;
    Edge(int v, int u, int cap, int cost) : v(v), u(u), cap(cap), cost(cost) {}
  };

  int n, s, t;
  Dinitz(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
  }

  vector<Edge> edges;
  vector<vector<int>> adj;
  void add_edge(int v, int u, int cap, int cost) {
    edges.eb(v, u, cap, cost);
    adj[v].pb(sz(edges)-1);
    edges.eb(u, v, 0, -cost);
    adj[u].pb(sz(edges)-1);
  }

  vector<int> dist;
  bool spfa() {
    dist.assign(n, LLINF);

    queue<int> Q;
    vector<bool> inqueue(n, false);

    dist[s] = 0;
    Q.push(s);
    inqueue[s] = true;

    vector<int> cnt(n);

    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      inqueue[v] = false;

      for (auto eid : adj[v]) {
        auto const& e = edges[eid];
        if (e.cap - e.flow <= 0) continue;
        if (dist[e.u] > dist[e.v] + e.cost) {
          dist[e.u] = dist[e.v] + e.cost;
          if (!inqueue[e.u]) {
            Q.push(e.u);
            inqueue[e.u] = true;
          }
        }
      }
    }

    return dist[t] != LLINF;
  }

  int cost = 0;
  vector<int> ptr;
  int dfs(int v, int f) {
    if (v == t || f == 0) return f;
    for (auto &cid = ptr[v]; cid < sz(adj[v]);) {
      auto eid = adj[v][cid];
      auto &e = edges[eid];
      cid++;
      if (e.cap - e.flow <= 0) continue;
      if (dist[e.v] + e.cost != dist[e.u]) continue;
      int newf = dfs(e.u, min(f, e.cap-e.flow));
      if (newf == 0) continue;
      e.flow += newf;
      edges[eid^1].flow -= newf;
      cost += e.cost * newf;
      return newf;
    }
    return 0;
  }

  int total_flow = 0;
  int flow() {
    while (spfa()) {
      ptr.assign(n, 0);
      while (int newf = dfs(s, LLINF))
        total_flow += newf;
    }
    return total_flow;
  }
};
